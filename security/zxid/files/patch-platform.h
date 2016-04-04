--- platform.h.orig	2016-02-29 00:16:50 UTC
+++ platform.h
@@ -132,6 +132,7 @@ unsigned int alarm(unsigned int secs);
  * NOT MINGW nor WIN32CL (i.e. its Unix) */
 
 #include <dirent.h>
+#include <sys/types.h>
 
 #ifdef __cplusplus
 extern "C" {
