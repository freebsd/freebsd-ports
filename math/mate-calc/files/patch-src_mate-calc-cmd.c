--- src/mate-calc-cmd.c.orig	2013-03-24 20:56:44.000000000 -0500
+++ src/mate-calc-cmd.c	2013-03-24 20:58:28.000000000 -0500
@@ -8,10 +8,12 @@
  * license.
  */
 
+#include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#include <sys/param.h>
 #include <time.h>
 #include <locale.h>
 
@@ -22,6 +24,77 @@
 
 static MpSerializer *result_serializer;
 
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
