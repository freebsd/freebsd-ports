--- ./getline.h.orig	2009-03-23 18:40:41.000000000 +0000
+++ ./getline.h	2009-03-23 18:40:20.000000000 +0000
@@ -36,8 +36,13 @@
 int
 getline PARAMS ((char **_lineptr, size_t *_n, FILE *_stream));
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version <= 800066
 int
 getdelim PARAMS ((char **_lineptr, size_t *_n, int _delimiter, FILE *_stream));
+#endif
+#endif
 
 # endif
 
