--- src/file.c.orig	Wed Dec  8 08:37:40 2004
+++ src/file.c	Wed Dec 29 22:54:42 2004
@@ -70,6 +70,10 @@
 #   include <string.h>
 #endif
 
+#ifndef ENODATA
+#define ENODATA 61
+#endif
+
 
 /*############################################################*/
 /* file_getDirOfPath */
