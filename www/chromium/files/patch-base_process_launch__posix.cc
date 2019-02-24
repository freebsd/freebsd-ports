--- base/process/launch_posix.cc.orig	2019-01-30 02:17:39.000000000 +0100
+++ base/process/launch_posix.cc	2019-01-31 20:45:00.397199000 +0100
@@ -63,6 +63,7 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#pragma weak environ
 extern char** environ;
 
 namespace base {
