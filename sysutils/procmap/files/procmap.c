/****************************************************************************
 *
 * Copyright (C) 2000 Jason Evans <jasone@freebsd.org>.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice(s), this list of conditions and the following disclaimer as
 *    the first lines of this file unmodified other than the possible
 *    addition of one or more copyright notices.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice(s), this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************
 *
 * Reliably print the entire contents of the proc filesystem's "map" files.
 *
 * $FreeBSD$
 *
 ****************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

/* The longest possible path is "/proc/curproc/map". */
#define MAXPATH 18
#define MINBUF 4096

int
main(int argc, char **argv)
{
	char	*buf;
	char	path[MAXPATH] = "/proc/";
	int	mfd, bytes, size = MINBUF;
	
	if (argc != 2) {
		fprintf(stderr, "usage: procmap {<pid> | curproc}\n");
		exit(1);
	} else if (strlen(argv[1]) > 7) {
		fprintf(stderr, "procmap: <pid> too long.\n");
		fprintf(stderr, "usage: procmap {<pid> | curproc}\n");
		exit(1);
	}

	/* Open the map file. */
	snprintf(path, MAXPATH, "/proc/%s/map", argv[1]);
	mfd = open(path, O_RDONLY);
	if (mfd < 0) {
		fprintf(stderr, "Unable to open() %s: %s\n",
		    path, strerror(errno));
		exit(1);
	}
	
	/*
	 * Start out with a MINBUF byte buffer, and double the buffer size until
	 * it's big enough to read the whole map at once.
	 */
	buf = (char *)malloc(size);
	if (buf == NULL) {
		fprintf(stderr, "malloc() error\n");
		exit(1);
	}
	bzero(buf, size);
	
	for (;;) {
		if (lseek(mfd, 0, SEEK_SET) < 0) {
			fprintf(stderr, "lseek() error: %s\n",
				strerror(errno));
			exit(1);
		}
		/* Leave space for a NULL terminator at the end of buf. */
		if (bytes = read(mfd, buf, size - 1) < 0) {
			if (errno == EFBIG) {
				/* Buffer to small; try again. */
				size <<= 1;
				buf = (char *)realloc(buf, size);
				if (buf == NULL) {
					fprintf(stderr, "malloc() error\n");
					exit(1);
				}
				bzero(buf, size);
			} else {
				fprintf(stderr, "read() error: %s\n",
				    strerror(errno));
				exit(1);
			}
		} else {
			/* Success.  The results are in buf. */
			break;
		}
	}

	/*
	 * Write out a header, then the result.
	 *
	 * format: start, end, resident, private resident, cow, access, type.
	 */
	printf("start end resident priv_res cow access type\n");
	printf("%s", buf);
	
	return 0;
}
