/*	$NetBSD: digest.c,v 1.8 2003/07/24 00:27:09 atatat Exp $ */

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
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <digest-types.h>

#ifndef lint
__COPYRIGHT("@(#) Copyright (c) 2001 \
	        The NetBSD Foundation, Inc.  All rights reserved.");
__RCSID("$NetBSD: digest.c,v 1.8 2003/07/24 00:27:09 atatat Exp $");
#endif


#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif
#ifdef HAVE_LOCALE_H
#include <locale.h>
#endif
#include <md5.h>
#include <rmd160.h>
#include <sha1.h>
#include <sha2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

typedef void (*HASH_init)(void *);
typedef void (*HASH_update)(void *, const unsigned char *, unsigned int);
typedef char *(*HASH_end)(void *, char *);
typedef char *(*HASH_file)(char *, char *);
  
/* this struct defines a message digest algorithm */
typedef struct alg_t {
	const char     *name;
	int		hash_len;
	HASH_init	hash_init;
	HASH_update	hash_update;
	HASH_end	hash_end;
	HASH_file	hash_file;
	union {
		MD5_CTX		m;
		SHA1_CTX	sha;
		RMD160_CTX	rmd;
		SHA256_CTX	sha256;
		SHA384_CTX	sha384;
		SHA512_CTX	sha512;
	} hash_ctx, hash_ctx2;
} alg_t;

/* list of supported message digest algorithms */
static alg_t algorithms[] = {
	{ "MD5",	16,
	  (HASH_init) MD5Init,		(HASH_update) MD5Update,
	  (HASH_end) MD5End,		(HASH_file) MD5File },
	{ "RMD160",	20,
	  (HASH_init) RMD160Init,	(HASH_update) RMD160Update,
	  (HASH_end) RMD160End,		(HASH_file) RMD160File },
	{ "SHA1",	20,
	  (HASH_init) SHA1Init,		(HASH_update) SHA1Update,
	  (HASH_end) SHA1End,		(HASH_file) SHA1File },
	{ "SHA256",	SHA256_DIGEST_LENGTH,
	  (HASH_init) SHA256_Init,	(HASH_update) SHA256_Update,
	  (HASH_end) SHA256_End,	(HASH_file) SHA256_File },
	{ "SHA384",	SHA384_DIGEST_LENGTH,
	  (HASH_init) SHA384_Init,	(HASH_update) SHA384_Update,
	  (HASH_end) SHA384_End,	(HASH_file) SHA384_File },
	{ "SHA512",	SHA512_DIGEST_LENGTH,
	  (HASH_init) SHA512_Init,	(HASH_update) SHA512_Update,
	  (HASH_end) SHA512_End,	(HASH_file) SHA512_File },
	{ NULL }
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

/* compute a digest, and print the results if successful */
static int
digest_file(char *fn, alg_t *alg)
{
	char	in[BUFSIZ * 20];
	char   *digest;
	int	cc, rc;

	digest = malloc(alg->hash_len * 2 + 1);

        if (fn == NULL) {
		(*alg->hash_init)(&alg->hash_ctx);
                while ((cc = read(STDIN_FILENO, in, sizeof(in))) > 0) {
			(*alg->hash_update)(&alg->hash_ctx, (u_char *)in,
					    (unsigned) cc);
		}
		(void) printf("%s\n", (*alg->hash_end)(&alg->hash_ctx, digest));
		rc = 1;
	} else {
		if ((*alg->hash_file)(fn, digest) == NULL) {
			rc = 0;
		} else {
			(void) printf("%s (%s) = %s\n", alg->name, fn, digest);
			rc = 1;
		}
	}

	return (rc);
}

int
main(int argc, char **argv)
{
	alg_t  *alg;
	int	rval;
	int	i;

#ifdef HAVE_SETLOCALE
	(void) setlocale(LC_ALL, "");
#endif
	while ((i = getopt(argc, argv, "V")) != -1) {
		switch(i) {
		case 'V':
			printf("%s\n", VERSION);
			return EXIT_SUCCESS;
		}
	}
	argc -= optind;
	argv += optind;
	
	if (argc == 0) {
		(void) fprintf(stderr, "Usage: %s algorithm [file...]\n",
		    argv[-optind]);
		return EXIT_FAILURE;
	}
	if ((alg = find_algorithm(argv[0])) == NULL) {
		(void) fprintf(stderr, "No such algorithm `%s'\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	argc--;
	argv++;
	rval = EXIT_SUCCESS;
	if (argc == 0) {
		if (!digest_file(NULL, alg)) {
			(void) fprintf(stderr, "stdin\n");
			rval = EXIT_FAILURE;
		}
	} else {
		for (i = 0 ; i < argc ; i++) {
			if (!digest_file(argv[i], alg)) {
				(void) fprintf(stderr, "%s\n", argv[i]);
				rval = EXIT_FAILURE;
			}
		}
	}
	return rval;
}
