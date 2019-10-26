--- src/3rdparty/chromium/base/process/launch_posix.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/base/process/launch_posix.cc
@@ -64,6 +64,7 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#pragma weak environ
 extern char** environ;
 
 namespace base {
