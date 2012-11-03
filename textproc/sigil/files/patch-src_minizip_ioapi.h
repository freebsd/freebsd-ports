--- src/minizip/ioapi.h.orig	2012-10-27 20:24:40.000000000 +0400
+++ src/minizip/ioapi.h	2012-11-02 19:04:46.652602414 +0400
@@ -44,7 +44,13 @@
 #include <stdlib.h>
 #include "zlib.h"
 
-#if defined(USE_FILE32API)
+#if defined(__FreeBSD__)
+        #define FILE_FUNCTIONS_64B_BY_DEFAULT
+#else
+        #undef FILE_FUNCTIONS_64B_BY_DEFAULT
+#endif
+
+#if defined(USE_FILE32API) || defined(FILE_FUNCTIONS_64B_BY_DEFAULT)
 #define fopen64 fopen
 #define ftello64 ftell
 #define fseeko64 fseek
