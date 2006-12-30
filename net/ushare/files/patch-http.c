--- src/http.c.orig	Sun Nov 12 13:40:35 2006
+++ src/http.c	Sat Dec 23 02:47:10 2006
@@ -47,6 +47,10 @@
 #include "trace.h"
 #include "presentation.h"
 
+#if defined(__FreeBSD__)
+#include "strndup.h"
+#endif
+
 struct web_file_t {
   char *fullpath;
   size_t pos;
