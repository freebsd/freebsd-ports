--- base/process/launch_posix.cc.orig	2019-06-04 18:55:15 UTC
+++ base/process/launch_posix.cc
@@ -65,6 +65,7 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#pragma weak environ
 extern char** environ;
 
 namespace base {
