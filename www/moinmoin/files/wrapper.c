/*
  MoinMoin setuid wrapper by perky
  $FreeBSD$
*/
#include <unistd.h>

int
main(int argc, char *argv[], char *envp[])
{
	char *margv[] = { PYTHON_PATH, MOIN_PREFIX"/cgi-bin/moin.cgi", NULL };

	chdir(MOIN_PREFIX);
	return execve(PYTHON_PATH, margv, envp);
}
