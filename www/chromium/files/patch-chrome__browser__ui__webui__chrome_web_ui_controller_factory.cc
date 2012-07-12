--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2012-05-30 10:01:56.000000000 +0300
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc	2012-06-05 21:58:25.000000000 +0300
@@ -320,7 +320,7 @@
       url.host() == chrome::kChromeUIStatsHost ||
       url.host() == chrome::kChromeUITermsHost ||
       url.host() == chrome::kChromeUIVersionHost
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
       || url.host() == chrome::kChromeUILinuxProxyConfigHost
       || url.host() == chrome::kChromeUISandboxHost
 #endif
