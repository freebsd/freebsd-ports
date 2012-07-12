--- chrome/browser/chrome_content_browser_client.cc.orig	2012-05-30 10:01:59.000000000 +0300
+++ chrome/browser/chrome_content_browser_client.cc	2012-06-05 21:38:09.000000000 +0300
@@ -132,7 +132,7 @@
 #include "chrome/browser/chrome_browser_main_extra_parts_ash.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_ANDROID)
 #include "base/linux_util.h"
 #include "chrome/browser/crash_handler_host_linuxish.h"
 #endif
