/*
 * fsck_ext2fs - wrapper for e2fsck on FreeBSD
 * Copyright (C) 2004 Matthias Andree
 * redistributable in accordance with the
 * GNU General Public License v2
 *
 * $FreeBSD$
 *
 * Upstream: $Id: fsck_ext2fs.c,v 1.2 2004/02/24 20:57:02 emma Exp $
 *
 * format: gindent -kr
 */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

__attribute__ ((noreturn))
static int die(const char *tag)
{
	perror(tag);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	int ch, i = 1, force = 0, status;
	long block = 0;
	enum { normal, preen, yes, no } mode = normal;
	char *cmd[256];
	pid_t pid;

	cmd[0] = "/sbin/e2fsck";
	while ((ch = getopt(argc, argv, "BFpfnyb:")) != -1) {
		switch (ch) {
		case 'p':
			mode = preen;
			break;
		case 'f':
			force = 1;
			break;
		case 'n':
			mode = no;
			break;
		case 'y':
			mode = yes;
			break;
		case 'b':
			block = atol(optarg);
			break;
		case 'B':
		case 'F':
		default:
			fprintf(stderr, "%s: unknown option -%c\n",
				argv[0], optopt);
			exit(EXIT_FAILURE);
		}
	}

	if (force)
		cmd[i++] = "-f";

	switch (mode) {
	case normal:
		break;
	case yes:
		cmd[i++] = "-y";
		break;
	case no:
		cmd[i++] = "-n";
		break;
	case preen:
		cmd[i++] = "-p";
		break;
	}

	if (block) {
		static char b[30];

		sprintf(b, "-b %ld", block);
		cmd[i++] = b;
	}

	while (optind < argc)
		cmd[i++] = argv[optind++];

	cmd[i++] = 0;

	pid = fork();
	switch (pid) {
	case -1:
		/* error */
		die("fork");
		break;
	case 0:
		/* child */
		(void) execv(cmd[0], cmd);
		perror("execve");
		_exit(127);
	default:
		/* parent */
		if (pid != waitpid(pid, &status, 0))
			die("waitpid");
		if (WIFSIGNALED(status)
		    || (WIFEXITED(status) && WEXITSTATUS(status) >= 4))
			exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
