--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2012-05-19 23:59:57.030106018 +0300
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc	2012-05-20 00:01:25.136350422 +0300
@@ -322,7 +322,7 @@
 #if defined(USE_TCMALLOC)
       || url.host() == chrome::kChromeUITCMallocHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
       || url.host() == chrome::kChromeUILinuxProxyConfigHost
       || url.host() == chrome::kChromeUISandboxHost
 #endif
