--- ./src/other.c.orig	2012-05-02 13:52:56.000000000 -0400
+++ ./src/other.c	2012-05-06 13:52:32.000000000 -0400
@@ -53,13 +53,28 @@
 
 #include <err.h>
 #include <errno.h>
+#ifndef __FreeBSD__
 #include <error.h>
+#endif
 #include <stdbool.h>
 #include <stddef.h>
 #include <stdio.h>
+#ifndef __FreeBSD__
 #include <stdio_ext.h>
+#endif
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#define error errc
+#endif
+
+#ifdef __FreeBSD__
+static size_t __fpending (FILE *fp)
+{
+	return (fp->_p - fp->_bf._base);
+}
+#endif
+
 /* Simple memory allocation wrapper */
 void *safe_malloc(const size_t size)
 {
