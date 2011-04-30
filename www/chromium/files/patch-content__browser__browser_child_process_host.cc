--- ./content/browser/browser_child_process_host.cc.orig	2010-12-16 02:11:58.000000000 +0100
+++ ./content/browser/browser_child_process_host.cc	2010-12-20 20:15:08.000000000 +0100
@@ -27,9 +27,9 @@
 #include "chrome/common/result_codes.h"
 #include "chrome/installer/util/google_update_settings.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "base/linux_util.h"
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_FREEBSD
 
 namespace {
 
