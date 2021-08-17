#include <iostream>
#include <cstdlib>
#include<cmath>
#include<ctime>
#include "F:\New folder\collage\FCI-CB\DS & Algo\weeks\week 2\04-Stack-Array-Based.cpp"
using namespace std;

class ball_sort
{
private:

const int N = 4;
const int M = 5;
const int X = 3;

public:

    stack1 a,b,c,d,e;
    stack1 grid[5]={a,b,c,d,e};


//This function prints the grid
void print_grid() {
	cout << "\n";
	cout << "  ";
    for (int i = 0; i < M; cout << "   ", i++);
    cout << "  \n";
    for (int i = 0; i < N; i++) {
        cout << "| ";
        cout << grid[0].arr[i] << " |   | " << grid[1].arr[i] << " |   | "  << grid[2].arr[i] << " |   | "
        << grid[3].arr[i] << " |   | " << grid[4].arr[i] << " | " ;
        cout << " \n";
        cout << "| ";
        for (int i = 0; i < M; cout << "  |   | ", i++);
        cout << "  \n";
    }
    for (int i = 0; i < M; cout << " ----   ", i++);
    cout << "\n";
}

//This function checks if the game has a win state or not
bool check_win() {
    for(int i=0 ; i<M ; i++){
        for (int j = 0; j < N-1; j++){   
            if( grid[i].arr[j]!=grid[i].arr[j+1] ){
                return false;
            }
        }
    }
    return true;
}

//This function checks if given position is valid or not
bool check_valid_column(int i, int j) {
    bool valid = 0<i && i<=M && 0<j && j<=M 
                && grid[i-1].top()==grid[j-1].top() || grid[j-1].top()==INT_MAX;
    return valid;
}

//This function clears the game structures
void grid_clear() { 
    for (int i =0 ; i<M ; i++){
        for (int j =0 ; j<N ; j++){
            grid[i].arr[j]=0;
        } 
        grid[i].n=0;
    }
    /*stack1 a,b,c,d,e;
    grid[0]=a;
    grid[1]=b;
    grid[2]=c;
    grid[3]=d;
    grid[4]=e;*/
}

//move 
void set_cell(int i,int j){
    int value=grid[i-1].top();
        grid[i-1].pop();
        for(int j=grid[i-1].n ; j<N ; j++){
        grid[i-1].arr[j]=0;}
        grid[j-1].push(value);
        for(int l=grid[j-1].n ; l<N ; l++){
        grid[j-1].arr[l]=0;}
}

//This function generates numbers
void generate_number() {

    srand( (unsigned)time( NULL ) );

    for(int i =0 ; i<N ;i++ ){
        int f = rand() % X +1;
        while ((grid[0].countNumber(f)+grid[1].countNumber(f)+grid[2].countNumber(f))>=4){
            f = rand() % X +1;
        }
        grid[0].push(f);
    }

    for(int i =0 ; i<N ;i++ ){
        int f = rand() % X +1;
        while ((grid[0].countNumber(f)+grid[1].countNumber(f)+grid[2].countNumber(f))>=4){
            f = rand() % X +1;
        }
        grid[1].push(f);
    }

    for(int i =0 ; i<N ;i++ ){
        int f = rand() % X +1;
        while ((grid[0].countNumber(f)+grid[1].countNumber(f)+grid[2].countNumber(f))>=4){
            f = rand() % X +1;
        }
        grid[2].push(f);
    }

}

//1=a , 2=b ,  3=c , 4=d , 5=e
bool check_full(int i){
    if(grid[i-1].arr[N-1]!=0){
        return true;}
    else{
    return false;}
}

//This function reads a valid position input
void read_input(int &i , int &j) {
    cout << "Enter the column index: ";
    cin >> i >> j;    
    while (!check_valid_column(i,j) || check_full(j)) {
        cout << "Enter a valid column index: ";
        cin >> i >> j;
    }
}

//MAIN FUNCTION
void play_game() {
    cout << "numbers sort game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input from the player
        int i,j;
		read_input(i,j);
        //Set the input position with the mark
        set_cell(i, j);
        //Check if the state of the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Congrats, you won!\n";
            break;
        }
        //Check if the state of the grid has a tie state
        /*if (check_tie()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Woah! That's a tie!\n";
            break;
        }*/
    }
}
    
};

int main() {
    while (true) {
        ball_sort b;
    	b.grid_clear();
      b.generate_number();
    	b.play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
} 
