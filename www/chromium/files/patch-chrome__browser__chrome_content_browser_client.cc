--- chrome/browser/chrome_content_browser_client.cc.orig	2012-04-25 10:02:36.000000000 +0300
+++ chrome/browser/chrome_content_browser_client.cc	2012-04-29 20:18:40.000000000 +0300
@@ -132,7 +132,7 @@
 #include "chrome/browser/chrome_browser_main_extra_parts_ash.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/linux_util.h"
 #include "chrome/browser/crash_handler_host_linux.h"
 #endif
