--- xbmc/linux/XFileUtils.cpp.orig	2014-12-20 16:29:11 UTC
+++ xbmc/linux/XFileUtils.cpp
@@ -36,6 +36,7 @@
 #endif
 #include <dirent.h>
 #include <errno.h>
+#include <stdlib.h>
 
 #if defined(TARGET_ANDROID)
 #include <sys/file.h>
