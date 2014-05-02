/*
 ============================================================================
 Name        : NQueens.c
 Author      : Somshubra Majumdar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int check(int *a, int r);
void printSolution(int *a, int n,int count);
void NQueens(int *a, int n, int r);

int main(void) {
	int n,*a = NULL;
	setbuf(stdout, NULL);

	printf("Enter the number of Queens : ");
	scanf("%d",&n);

	a = (int*) calloc(n, sizeof(int));

	NQueens(a,n,0);
	return EXIT_SUCCESS;
}

int check(int *a, int r){
	int i;

	for(i = 0; i < r; i++){

		if(a[i] == a[r] || abs(r-i) == abs(a[r] - a[i])){
			return 0;
		}
	}

	return 1;
}

void printSolution(int *a, int n, int count){

	int i;
	printf("Solution %d\n", count);
	for(i = 0; i < n; i++){

		printf("Queen : %d is placed in position %d\n",i+1,a[i]);
	}

	printf("\n");
}

int c;
void NQueens(int *a, int n, int r){
	int i;

	for(i = 0; i < n; i++){

		a[r] = i;

		if(check(a,r)){

			if(r+1 < n){
				NQueens(a, n,r+1);
			}
			else{
				printSolution(a,n,c++);
			}
		}
	}
}
