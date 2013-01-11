--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2012-11-27 10:02:11.000000000 +0200
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc	2012-11-28 21:02:24.000000000 +0200
@@ -366,7 +366,7 @@
       url.host() == chrome::kChromeUIMemoryRedirectHost ||
       url.host() == chrome::kChromeUIStatsHost ||
       url.host() == chrome::kChromeUITermsHost
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
       || url.host() == chrome::kChromeUILinuxProxyConfigHost
       || url.host() == chrome::kChromeUISandboxHost
 #endif
