--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ bgpctl/fmt_scaled.c	8 Feb 2007 10:32:19 -0000
@@ -0,0 +1,152 @@
+/*	$OpenBSD: fmt_scaled.c,v 1.8 2005/10/19 18:48:11 deraadt Exp $	*/
+
+/*
+ * Copyright (c) 2001, 2002, 2003 Ian F. Darwin.  All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. The name of the author may not be used to endorse or promote products
+ *    derived from this software without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
+ * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
+ * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
+ * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
+ * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
+ * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
+ * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
+ * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
+ * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
+ * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
+ */
+
+/*
+ * fmt_scaled: Format numbers scaled for human comprehension
+ * scan_scaled: Scan numbers in this format.
+ *
+ * "Human-readable" output uses 4 digits max, and puts a unit suffix at
+ * the end.  Makes output compact and easy-to-read esp. on huge disks.
+ * Formatting code was originally in OpenBSD "df", converted to library routine.
+ * Scanning code written for OpenBSD libutil.
+ */
+
+#include <stdio.h>
+#include <stdlib.h>
+#include <errno.h>
+#include <string.h>
+#include <ctype.h>
+#include <limits.h>
+
+#include "util.h"
+
+typedef enum {
+	NONE = 0, KILO = 1, MEGA = 2, GIGA = 3, TERA = 4, PETA = 5, EXA = 6
+} unit_type;
+
+/* These three arrays MUST be in sync!  XXX make a struct */
+static unit_type units[] = { NONE, KILO, MEGA, GIGA, TERA, PETA, EXA };
+static char scale_chars[] = "BKMGTPE";
+static long long scale_factors[] = {
+	1LL,
+	1024LL,
+	1024LL*1024,
+	1024LL*1024*1024,
+	1024LL*1024*1024*1024,
+	1024LL*1024*1024*1024*1024,
+	1024LL*1024*1024*1024*1024*1024,
+};
+#define	SCALE_LENGTH (sizeof(units)/sizeof(units[0]))
+
+#define MAX_DIGITS (SCALE_LENGTH * 3)	/* XXX strlen(sprintf("%lld", -1)? */
+
+/* Format the given "number" into human-readable form in "result".
+ * Result must point to an allocated buffer of length FMT_SCALED_STRSIZE.
+ * Return 0 on success, -1 and errno set if error.
+ */
+int
+fmt_scaled(long long number, char *result)
+{
+	long long abval, fract = 0;
+	unsigned int i;
+	unit_type unit = NONE;
+
+	abval = (number < 0LL) ? -number : number;	/* no long long_abs yet */
+
+	/* Not every negative long long has a positive representation.
+	 * Also check for numbers that are just too darned big to format
+	 */
+	if (abval < 0 || abval / 1024 >= scale_factors[SCALE_LENGTH-1]) {
+		errno = ERANGE;
+		return -1;
+	}
+
+	/* scale whole part; get unscaled fraction */
+	for (i = 0; i < SCALE_LENGTH; i++) {
+		if (abval/1024 < scale_factors[i]) {
+			unit = units[i];
+			fract = (i == 0) ? 0 : abval % scale_factors[i];
+			number /= scale_factors[i];
+			if (i > 0)
+				fract /= scale_factors[i - 1];
+			break;
+		}
+	}
+
+	fract = (10 * fract + 512) / 1024;
+	/* if the result would be >= 10, round main number */
+	if (fract == 10) {
+		if (number >= 0)
+			number++;
+		else
+			number--;
+		fract = 0;
+	}
+
+	if (number == 0)
+		strlcpy(result, "0B", FMT_SCALED_STRSIZE);
+	else if (unit == NONE || number >= 100 || number <= -100) {
+		if (fract >= 5) {
+			if (number >= 0)
+				number++;
+			else
+				number--;
+		}
+		(void)snprintf(result, FMT_SCALED_STRSIZE, "%lld%c",
+			number, scale_chars[unit]);
+	} else
+		(void)snprintf(result, FMT_SCALED_STRSIZE, "%lld.%1lld%c",
+			number, fract, scale_chars[unit]);
+
+	return 0;
+}
+
+#ifdef	MAIN
+/*
+ * This is the original version of the program in the man page.
+ * Copy-and-paste whatever you need from it.
+ */
+int
+main(int argc, char **argv)
+{
+	char *cinput = "1.5K", buf[FMT_SCALED_STRSIZE];
+	long long ninput = 10483892, result;
+
+	if (scan_scaled(cinput, &result) == 0)
+		printf("\"%s\" -> %lld\n", cinput, result);
+	else
+		perror(cinput);
+
+	if (fmt_scaled(ninput, buf) == 0)
+		printf("%lld -> \"%s\"\n", ninput, buf);
+	else
+		fprintf(stderr, "%lld invalid (%s)\n", ninput, strerror(errno));
+
+	return 0;
+}
+#endif
Index: util.h
===================================================================
RCS file: util.h
diff -N util.h
