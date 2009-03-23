--- ./getline.c.orig	2009-03-23 18:42:33.000000000 +0000
+++ ./getline.c	2009-03-23 19:03:49.000000000 +0000
@@ -45,7 +45,15 @@
 }
 
 #else /* ! have getdelim */
+
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version <= 800066
 int
+#else
+ssize_t
+#endif
+#endif
 getdelim (lineptr, n, delimiter, stream);
 
 # include <assert.h>
@@ -150,7 +158,14 @@
   return getstr (lineptr, n, stream, '\n', 0);
 }
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version <= 800066
 int
+#else
+ssize_t
+#endif
+#endif
 getdelim (lineptr, n, delimiter, stream)
      char **lineptr;
      size_t *n;
