--- chrome/browser/chrome_content_browser_client.cc.orig	2011-06-29 20:38:10.627569565 +0300
+++ chrome/browser/chrome_content_browser_client.cc	2011-06-29 20:38:47.261569975 +0300
@@ -48,7 +48,7 @@
 #include "net/base/cookie_monster.h"
 #include "net/base/cookie_options.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "base/linux_util.h"
 #include "chrome/browser/crash_handler_host_linux.h"
 #endif
@@ -323,7 +323,7 @@
 #endif
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 int ChromeContentBrowserClient::GetCrashSignalFD(
     const std::string& process_type) {
   if (process_type == switches::kRendererProcess)
