--- src/gcalccmd.c.orig	2009-12-08 21:27:37.000000000 -0500
+++ src/gcalccmd.c	2010-01-24 13:38:19.000000000 -0500
@@ -18,16 +18,89 @@
  *  02111-1307, USA.
  */
 
+#include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#include <sys/param.h>
 #include <time.h>
 
 #include "mp-equation.h"
 
 #define MAXLINE 1024
 
+#if __FreeBSD_version < 800067
+static ssize_t
+getline (char **lineptr, size_t *n, FILE *stream)
+{
+    char *line, *p;
+    long size, copy;
+
+    if (lineptr == NULL || n == NULL) {
+		errno = EINVAL;
+		return (ssize_t) -1;
+	}
+
+	if (ferror (stream))
+		return (ssize_t) -1;
+
+	/* Make sure we have a line buffer to start with.  */
+	if (*lineptr == NULL || *n < 2) /* !seen and no buf yet need 2 chars.  */ {
+#ifndef        MAX_CANON
+#define        MAX_CANON        256
+#endif
+		if (!*lineptr)
+			line = (char *) malloc (MAX_CANON);
+		else
+			line = (char *) realloc (*lineptr, MAX_CANON);
+		if (line == NULL)
+				return (ssize_t) -1;
+		*lineptr = line;
+		*n = MAX_CANON;
+	}
+
+	line = *lineptr;
+	size = *n;
+
+	copy = size;
+	p = line;
+
+	while (1) {
+		long len;
+
+		while (--copy > 0) {
+			int c = getc (stream);
+
+			if (c == EOF)
+				goto lose;
+			else if ((*p++ = c) == '\n')
+				goto win;
+		}
+
+		/* Need to enlarge the line buffer.  */
+		len = p - line;
+		size *= 2;
+		line = (char *) realloc (line, size);
+		if (line == NULL)
+			goto lose;
+		*lineptr = line;
+		*n = size;
+		p = line + len;
+		copy = size - len;
+	}
+
+lose:
+	if (p == *lineptr)
+		return (ssize_t) -1;
+
+	/* Return a partial line since we got an error in the middle.  */
+win:
+	*p = '\0';
+	return p - *lineptr;
+}
+#endif
+
 static void
 solve(const char *equation)
 {
