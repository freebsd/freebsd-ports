--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2014-10-10 09:15:30 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -508,7 +508,7 @@
       url.host() == chrome::kChromeUIMemoryRedirectHost ||
       url.host() == chrome::kChromeUIStatsHost ||
       url.host() == chrome::kChromeUITermsHost
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
       || url.host() == chrome::kChromeUILinuxProxyConfigHost
       || url.host() == chrome::kChromeUISandboxHost
 #endif
