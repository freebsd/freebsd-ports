--- xbmc/linux/XFileUtils.cpp.orig	2016-02-20 15:21:19 UTC
+++ xbmc/linux/XFileUtils.cpp
@@ -37,6 +37,7 @@
 #endif
 #include <dirent.h>
 #include <errno.h>
+#include <stdlib.h>
 
 #if defined(TARGET_ANDROID)
 #include <sys/file.h>
