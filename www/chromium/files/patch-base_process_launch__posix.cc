--- base/process/launch_posix.cc.orig	2022-06-17 14:20:10 UTC
+++ base/process/launch_posix.cc
@@ -63,6 +63,9 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#if defined(OS_FREEBSD)
+#pragma weak environ
+#endif
 extern char** environ;
 
 namespace base {
