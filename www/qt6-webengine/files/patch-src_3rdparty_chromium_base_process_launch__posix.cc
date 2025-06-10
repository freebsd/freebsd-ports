--- src/3rdparty/chromium/base/process/launch_posix.cc.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/base/process/launch_posix.cc
@@ -67,6 +67,9 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#if defined(OS_FREEBSD)
+#pragma weak environ
+#endif
 extern char** environ;
 
 namespace base {
