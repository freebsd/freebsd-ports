--- src/3rdparty/chromium/base/process/launch_posix.cc.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/process/launch_posix.cc
@@ -64,6 +64,7 @@
 #include "base/feature_list.h"
 #else
 extern char** environ;
+#pragma weak environ
 #endif
 
 namespace base {
