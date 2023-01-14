--- src/3rdparty/chromium/base/process/launch_posix.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/process/launch_posix.cc
@@ -64,6 +64,9 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#if defined(OS_FREEBSD)
+#pragma weak environ
+#endif
 extern char** environ;
 
 namespace base {
