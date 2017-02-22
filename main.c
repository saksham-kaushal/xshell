/* concept, idea and motivation from https://brennan.io/2015/01/16/write-a-shell-in-c/
*/ 


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


#define READ_BUFFER_SIZE 512




void prompt(void)

//can later change the prompt to print username, machne name, host etc.

{
	printf("$ ");
}




char *read_cmd(void)

//gets character,allocates memory dynamically if buffer is filled up. can change buffer size from global variable defined as READ_BUFFER_SIZE.

{
	int rl_buffer_size = READ_BUFFER_SIZE;	
	char *cmd_buffer= malloc(rl_buffer_size * sizeof(char));
	char cmd_char;	

	if (!cmd_buffer)
	{	
		fprintf(stderr,"buffer memory allocation error");
		exit();
	}

	while(1)
	{
		cmd_char= getc(stdin);  //used getc instead of getchar for later implementing input redirection.
		if (cmd_char==EOF || cmd_char=='\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
		{
			buffer[position]=c;
		}
		
		position++;

		if (position >= rl_buffer_size)
		{
			rl_buffer_size += READ_BUFFER_SIZE;
			test_buffer = realloc(cmd_buffer,rl_buffer_size); //confirm arguments from function prototype in stdlib.h
			if (test_buffer!=NULL)
			{
				cmd_buffer = test_buffer;
			}
			else
			{
				fprintf(stderr,"buffer memory allocation error");
			}
		}
	}
}


