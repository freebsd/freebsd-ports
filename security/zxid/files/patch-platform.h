--- platform.h.orig	2013-11-27 10:56:48.000000000 +0900
+++ platform.h	2014-07-28 07:51:37.000000000 +0900
@@ -130,6 +130,7 @@
  * NOT MINGW nor WIN32CL (i.e. its Unix) */
 
 #include <dirent.h>
+#include <sys/types.h>
 
 #ifdef __cplusplus
 extern "C" {
