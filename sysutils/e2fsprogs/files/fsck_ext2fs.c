/*
 * fsck_ext2fs - wrapper for e2fsck on FreeBSD
 * Copyright (C) 2004 Matthias Andree
 * redistributable in accordance with the
 * GNU General Public License v2
 *
 * $FreeBSD$
 *
 * format: gindent -kr
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
main(int argc, char **argv)
{
	int ch, i = 1, force = 0;
	long block = 0;
	enum { normal, preen, yes, no } mode = normal;
	char *cmd[256];

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

	(void)execv(cmd[0], cmd);
	exit(EXIT_FAILURE);
}
