/*
 * Copyright (C) 1996 Wolfgang Solfrank.
 * Copyright (C) 1996 TooLs GmbH.
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
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by TooLs GmbH.
 * 4. The name of TooLs GmbH may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD$
 */

/*
 * Stand-alone ISO9660 file reading package.
 *
 * Note: This doesn't support Rock Ridge extensions, extended attributes,
 * blocksizes other than 2048 bytes, multi-extent files, etc.
 */
#include <sys/param.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <err.h>
#include <isofs/cd9660/iso.h>

struct ptable_ent {
	char namlen	[ISODCL( 1, 1)];	/* 711 */
	char extlen	[ISODCL( 2, 2)];	/* 711 */
	char block	[ISODCL( 3, 6)];	/* 732 */
	char parent	[ISODCL( 7, 8)];	/* 722 */
	char name	[1];
};
#define	PTFIXSZ		8
#define	PTSIZE(pp)	roundup(PTFIXSZ + isonum_711((pp)->namlen), 2)

#define cdb2off(bno)	((bno) * ISO_DEFAULT_BLOCK_SIZE)

/* XXX these should be in the system headers */
static __inline int
isonum_722(u_char *p)
{
	return (*p << 8)|p[1];
}

static __inline int
isonum_732( u_char *p)
{
	return (*p << 24)|(p[1] << 16)|(p[2] << 8)|p[3];
}

static int
dirmatch(const char *path, struct iso_directory_record *dp)
{
	char *cp;
	int i;

	cp = dp->name;
	for (i = isonum_711(dp->name_len); --i >= 0; path++, cp++) {
		if (!*path || *path == '/')
			break;
		if (toupper(*path) == *cp)
			continue;
		return 0;
	}
	if (*path && *path != '/')
		return 0;
	/*
	 * Allow stripping of trailing dots and the version number.
	 * Note that this will find the first instead of the last version
	 * of a file.
	 */
	if (i >= 0 && (*cp == ';' || *cp == '.')) {
		/* This is to prevent matching of numeric extensions */
		if (*cp == '.' && cp[1] != ';')
			return 0;
		while (--i >= 0)
			if (*++cp != ';' && (*cp < '0' || *cp > '9'))
				return 0;
	}
	return 1;
}

static int
cd9660_findfile(int disk, const char *path, int *startp, int *lenp)
{
	void *buf;
	struct iso_primary_descriptor *vd;
	size_t buf_size, read, dsize, off;
	daddr_t bno, boff;
	struct iso_directory_record rec;
	struct iso_directory_record *dp = 0;
	int rc = 0;
	
	/* First find the volume descriptor */
	buf = malloc(buf_size = ISO_DEFAULT_BLOCK_SIZE);
	vd = buf;
	for (bno = 16;; bno++) {
		read = pread(disk, buf, ISO_DEFAULT_BLOCK_SIZE, cdb2off(bno));
		if (read != ISO_DEFAULT_BLOCK_SIZE) {
			rc = EIO;
			goto out;
		}
		rc = EINVAL;
		if (bcmp(vd->id, ISO_STANDARD_ID, sizeof vd->id) != 0)
			goto out;
		if (isonum_711(vd->type) == ISO_VD_END)
			goto out;
		if (isonum_711(vd->type) == ISO_VD_PRIMARY)
			break;
	}
	if (isonum_723(vd->logical_block_size) != ISO_DEFAULT_BLOCK_SIZE) {
		rc = EINVAL;
		goto out;
	}
	
	rec = *(struct iso_directory_record *) vd->root_directory_record;
	if (*path == '/') path++; /* eat leading '/' */

	while (*path) {
		bno = isonum_733(rec.extent) + isonum_711(rec.ext_attr_length);
		dsize = isonum_733(rec.size);
		off = 0;
		boff = 0;

		while (off < dsize) {
			if ((off % ISO_DEFAULT_BLOCK_SIZE) == 0) {
				read = pread(disk, buf,
					     ISO_DEFAULT_BLOCK_SIZE,
					     cdb2off(bno + boff));
				if (read != ISO_DEFAULT_BLOCK_SIZE) {
					rc = EIO;
					goto out;
				}
				boff++;
				dp = (struct iso_directory_record *) buf;
			}
			if (isonum_711(dp->length) == 0) {
			    /* skip to next block, if any */
			    off = boff * ISO_DEFAULT_BLOCK_SIZE;
			    continue;
			}

			if (dirmatch(path, dp))
				break;

			dp = (struct iso_directory_record *)
				((char *) dp + isonum_711(dp->length));
			off += isonum_711(dp->length);
		}
		if (off == dsize) {
			rc = ENOENT;
			goto out;
		}

		rec = *dp;
		while (*path && *path != '/') /* look for next component */
			path++;
		if (*path) path++; /* skip '/' */
	}

	*startp = cdb2off(isonum_733(rec.extent)
			  + isonum_711(rec.ext_attr_length));
	*lenp = isonum_733(rec.size);
	rc = 0;

 out:
	free(buf);
	return rc;
}

int
main(int argc, char *argv[])
{
	int disk, start, len, i;
	char buf[512];
	unsigned long long *lp, sum;

	if (argc != 3) {
		fprintf(stderr, "Usage: setcdboot <cd image> <boot path>\n");
		exit(1);
	}

	disk = open(argv[1], O_RDWR);
	if (disk < 0)
		err(1, "Can't open %s", argv[1]);
	if (cd9660_findfile(disk, argv[2], &start, &len))
		errx(1, "Can't find %s in image", argv[2]);
	printf("start=%d, len=%d\n", start, len);

	/*
	 * Read the SRM boot sector and write location of bootstrap.
	 */
	if (pread(disk, buf, 512, 0) < 0)
		errx(1, "Can't read boot sector");
	lp = (unsigned long long *) buf;
	lp[60] = (len + 511) / 512;
	lp[61] = start / 512;
	lp[62] = 0;

	/*
	 * Checksum the boot sector and write it back.
	 */
	sum = 0;
	for (i = 0; i < 63; i++)
		sum += lp[i];
	lp[63] = sum;
	
	if (pwrite(disk, buf, 512, 0) < 0)
		errx(1, "Can't write boot sector");

	return 0;
}
