--- src/3rdparty/chromium/base/process/launch_posix.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/process/launch_posix.cc
@@ -65,6 +65,7 @@
 #include "base/feature_list.h"
 #else
 extern char** environ;
+#pragma weak environ
 #endif
 
 namespace base {
