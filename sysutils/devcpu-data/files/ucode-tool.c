/*-
 * Copyright (c) 2013 John Clark <clarkjc@runbox.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/* $FreeBSD$ */
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/endian.h>
#include <unistd.h>

#define BUFFER_SIZE	4096

static void	error(const char *fmt, ...);
static void	process_amd(const char *container, const char *outdir);
static void	process_intel(const char *filename, const char *outdir);

/*
 * This tool extracts microcode from container files provided by
 * Intel and AMD for their families of popular microprocessors.
 */
int
main(int argc, char *argv[])
{
	int ch, i, mode = -1;
	char *outdir = ".";

	/* Parse the command line arguments. */
	while ((ch = getopt(argc, argv, "aio:")) != -1) {
		switch (ch) {
		case 'a':	/* Mode select */
		case 'i':
			mode = ch;
			break;
		case 'o':	/* Output directory */
			outdir = optarg;
			break;
		default:	/* Unknown */
			error("Error: Invalid argument\n");
		}
	}

	if (mode == 'i') {
		/* Process Intel microcode container files */
		for (i = optind; i < argc; i++) {
			process_intel(argv[i], outdir);
		}
	} else if (mode == 'a') {
		/* Process AMD microcode container files */
		for (i = optind; i < argc; i++) {
			process_amd(argv[i], outdir);
		}
	} else {
		error("Error: Invalid mode\n");
	}

	return 0;
}

/* Display an error message and exit with a status code of 1. */
static void
error(const char *fmt, ...)
{
	va_list args;

	if (fmt == NULL) {
		perror("Error");
	} else {
		va_start(args, fmt);
		vfprintf(stderr, fmt, args);
		va_end(args);
	}
	exit(1);
}

/* Process an AMD supplied microcode container file. */
#define AMD_HEADER_LEN		12
#define AMD_SKIP_OFFSET		8
#define AMD_UCODE_HEADER_LEN	8
#define AMD_UCODE_HEADER_TYPE	0x00000001
#define AMD_UCODE_ID_OFFSET	4
#define AMD_UCODE_SIG_OFFSET	24
static void
process_amd(const char *container, const char *outdir)
{
	char outname[FILENAME_MAX];
	const uint8_t magic[] = {
		0x44, 0x4d, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	FILE *fin, *fout;
	uint8_t *buf;
	uint32_t id, len, sig;
	int num;

	if ((buf = malloc(BUFFER_SIZE)) == NULL)
		error(NULL);

	/* Open the container file and read the header. */
	if ((fin = fopen(container, "rb")) == NULL)
		error(NULL);
	if (fread(buf, AMD_HEADER_LEN, 1, fin) != 1) {
		error("Error: Truncated file: %s\n", container);
	}

	/* Check the magic numbers. */
	if (memcmp(magic, buf, sizeof(magic)) != 0) {
		error("Error: Invalid file: %s\n", container);
	}

	/* Seek to the first microcode image. */
	if (fseek(fin, le32dec(buf + AMD_SKIP_OFFSET), SEEK_CUR) != 0)
		error(NULL);

	/* Read all microcode images. */
	while ((num = fread(buf, 1, AMD_UCODE_HEADER_LEN, fin)) != 0) {
		/* Read and validate the image. */
		if (num != AMD_UCODE_HEADER_LEN) {
			error("Error: Truncated file: %s\n", container);
		}
		if (le32dec(buf) != AMD_UCODE_HEADER_TYPE) {
			error("Error: Invalid type: %s\n", container);
		}
		len = le32dec(buf + sizeof(uint32_t));
		if (len > BUFFER_SIZE) {
			if ((buf = realloc(buf, len)) == NULL)
				error(NULL);
		}
		if (fread(buf, len, 1, fin) != 1) {
			error("Error: Truncated file: %s\n", container);
		}

		/* Write the image to an output file. */
		sig = le32dec(buf + AMD_UCODE_SIG_OFFSET);
		id = le32dec(buf + AMD_UCODE_ID_OFFSET);
		snprintf(outname, sizeof(outname), "%s/AMD-%08x-%08x.fw",
		    outdir, sig, id);
		if ((fout = fopen(outname, "wb")) == NULL)
			error(NULL);
		if (fwrite(buf, len, 1, fout) != 1)
			error(NULL);
		if (fclose(fout) != 0)
			error(NULL);
	}

	if (fclose(fin) != 0)
		error(NULL);
	free(buf);
}

/* Process an Intel supplied microcode container file. */
static void
process_intel(const char *container, const char *outdir)
{
	char outname[FILENAME_MAX];
	FILE *fin, *fout = NULL;
	char *buf, *token;
	const char * const sep = ",. \t\n";
	uint32_t val;

	if ((buf = malloc(BUFFER_SIZE)) == NULL)
		error(NULL);
	if ((fin = fopen(container, "r")) == NULL)
		error(NULL);

	/* Process the container file line by line. */
	while (fgets(buf, BUFFER_SIZE, fin) != NULL) {
		if ((token = strtok(buf, sep)) == NULL)
			continue;

		if (*token == '/') {
			/* Process a comment line. */
			if (fout != NULL) {
				/* Close previous output file. */
				if (fclose(fout) != 0)
					error(NULL);
				fout = NULL;
			}
			if ((token = strtok(NULL, sep)) != NULL) {
				/* Construct next file name. */
				snprintf(outname, sizeof(outname), "%s/%s.fw",
				    outdir, token);
			}
		} else {
			/* Process a data line. */
			if ((fout == NULL) && (token != NULL)) {
				if ((fout = fopen(outname, "wb")) == NULL)
					error(NULL);
			}
			while (token != NULL) {
				val = htole32(strtoul(token, NULL, 0));
				if (fwrite(&val, sizeof(val), 1, fout) != 1)
					error(NULL);
				token = strtok(NULL, sep);
			}
		}
	}

	if (fout != NULL) {
		if (fclose(fout) != 0)
			error(NULL);
	}
	if (fclose(fin) != 0)
		error(NULL);
	free(buf);
}
