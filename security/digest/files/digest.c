/*	$NetBSD: digest.c,v 1.3 2001/07/09 21:42:30 hubertf Exp $ */

/*
 * Copyright (c) 2001 Alistair G. Crooks.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by Alistair G. Crooks.
 * 4. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <sys/cdefs.h>

#ifndef lint
__COPYRIGHT("@(#) Copyright (c) 2001 \
	        The NetBSD Foundation, Inc.  All rights reserved.");
__RCSID("$NetBSD: digest.c,v 1.3 2001/07/09 21:42:30 hubertf Exp $");
#endif

#include <sys/types.h>

#include <locale.h>
#include <md5.h>
#include <rmd160.h>
#include <sha1.h>
#include <sha2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* perform an md5 digest, and print the results if successful */
static int
md5_digest_file(char *fn)
{
	MD5_CTX	m;
	char	in[BUFSIZ * 20];
	char	digest[33];
	int	cc;

	if (fn == NULL) {
		MD5Init(&m);
		while ((cc = read(STDIN_FILENO, in, sizeof(in))) > 0) {
			MD5Update(&m, (u_char *)in, (unsigned) cc);
		}
		(void) printf("%s\n", MD5End(&m, digest));
	} else {
		if (MD5File(fn, digest) == NULL) {
			return 0;
		}
		(void) printf("MD5 (%s) = %s\n", fn, digest);
	}
	return 1;
}

/* perform an sha1 digest, and print the results if successful */
static int
sha1_digest_file(char *fn)
{
	SHA1_CTX	sha;
	char		in[BUFSIZ * 20];
	char		digest[41];
	int		cc;

	if (fn == NULL) {
		SHA1Init(&sha);
		while ((cc = read(STDIN_FILENO, in, sizeof(in))) > 0) {
			SHA1Update(&sha, (u_char *)in, (unsigned) cc);
		}
		(void) printf("%s\n", SHA1End(&sha, digest));
	} else {
		if (SHA1File(fn, digest) == NULL) {
			return 0;
		}
		(void) printf("SHA1 (%s) = %s\n", fn, digest);
	}
	return 1;
}

/* perform an ripemd160 digest, and print the results if successful */
static int
rmd160_digest_file(char *fn)
{
	RMD160_CTX	rmd;
	char		in[BUFSIZ * 20];
	char		digest[41];
	int		cc;

	if (fn == NULL) {
		RMD160Init(&rmd);
		while ((cc = read(STDIN_FILENO, in, sizeof(in))) > 0) {
			RMD160Update(&rmd, (u_char *)in, (unsigned) cc);
		}
		(void) printf("%s\n", RMD160End(&rmd, digest));
	} else {
		if (RMD160File(fn, digest) == NULL) {
			return 0;
		}
		(void) printf("RMD160 (%s) = %s\n", fn, digest);
	}
	return 1;
}

/* perform a sha256 digest, and print the results if successful */
static int
sha256_digest_file(char *fn)
{
	SHA256_CTX	sha256;
	char		in[BUFSIZ * 20];
	char		digest[65];
	int		cc;

	if (fn == NULL) {
		SHA256_Init(&sha256);
		while ((cc = read(STDIN_FILENO, in, sizeof(in))) > 0) {
			SHA256_Update(&sha256, (u_char *)in, (unsigned) cc);
		}
		(void) printf("%s\n", SHA256_End(&sha256, digest));
	} else {
		if (SHA256_File(fn, digest) == NULL) {
			return 0;
		}
		(void) printf("SHA256 (%s) = %s\n", fn, digest);
	}
	return 1;
}

/* perform a sha384 digest, and print the results if successful */
static int
sha384_digest_file(char *fn)
{
	SHA384_CTX	sha384;
	char		in[BUFSIZ * 20];
	char		digest[97];
	int		cc;

	if (fn == NULL) {
		SHA384_Init(&sha384);
		while ((cc = read(STDIN_FILENO, in, sizeof(in))) > 0) {
			SHA384_Update(&sha384, (u_char *)in, (unsigned) cc);
		}
		(void) printf("%s\n", SHA384_End(&sha384, digest));
	} else {
		if (SHA384_File(fn, digest) == NULL) {
			return 0;
		}
		(void) printf("SHA384 (%s) = %s\n", fn, digest);
	}
	return 1;
}

/* perform a sha512 digest, and print the results if successful */
static int
sha512_digest_file(char *fn)
{
	SHA512_CTX	sha512;
	char		in[BUFSIZ * 20];
	char		digest[129];
	int		cc;

	if (fn == NULL) {
		SHA512_Init(&sha512);
		while ((cc = read(STDIN_FILENO, in, sizeof(in))) > 0) {
			SHA512_Update(&sha512, (u_char *)in, (unsigned) cc);
		}
		(void) printf("%s\n", SHA512_End(&sha512, digest));
	} else {
		if (SHA512_File(fn, digest) == NULL) {
			return 0;
		}
		(void) printf("SHA512 (%s) = %s\n", fn, digest);
	}
	return 1;
}

/* this struct defines a message digest algorithm */
typedef struct alg_t {
	const char     *name;			/* algorithm name */
	int		(*func)(char *);	/* function to call */
} alg_t;

/* list of supported message digest algorithms */
static alg_t algorithms[] = {
	{ "md5",	md5_digest_file		},
	{ "rmd160",	rmd160_digest_file	},
	{ "sha1",	sha1_digest_file	},
	{ "sha256",	sha256_digest_file	},
	{ "sha384",	sha384_digest_file	},
	{ "sha512",	sha512_digest_file	},
	{ NULL	}
};

/* find an algorithm, given a name */
static alg_t *
find_algorithm(const char *a)
{
	alg_t	*alg;

	for (alg = algorithms ; alg->name && strcasecmp(alg->name, a) != 0 ; alg++) {
	}
	return (alg->name) ? alg : NULL;
}

int
main(int argc, char **argv)
{
	alg_t  *alg;
	int	rval;
	int	i;

	(void) setlocale(LC_ALL, "");
	while ((i = getopt(argc, argv, "V")) != -1) {
		switch(i) {
		case 'V':
			printf("%d\n", VERSION);
			return EXIT_SUCCESS;
		}
	}
	if (argc == optind) {
		(void) fprintf(stderr, "Usage: %s algorithm [file...]\n", *argv);
		return EXIT_FAILURE;
	}
	if ((alg = find_algorithm(argv[optind])) == NULL) {
		(void) fprintf(stderr, "No such algorithm `%s'\n", argv[optind]);
		exit(EXIT_FAILURE);
	}
	rval = EXIT_SUCCESS;
	if (argc == optind + 1) {
		if (!(*alg->func)(NULL)) {
			(void) fprintf(stderr, "stdin\n");
			rval = EXIT_FAILURE;
		}
	} else {
		for (i = optind + 1 ; i < argc ; i++) {
			if (!(*alg->func)(argv[i])) {
				(void) fprintf(stderr, "%s\n", argv[i]);
				rval = EXIT_FAILURE;
			}
		}
	}
	return rval;
}
