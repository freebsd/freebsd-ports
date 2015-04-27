--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2015-04-19 00:04:55.000000000 +0200
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc	2015-04-19 00:05:15.000000000 +0200
@@ -249,7 +249,7 @@
 #if !defined(OS_ANDROID)
           || url.host() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
           || url.host() == chrome::kChromeUILinuxProxyConfigHost
           || url.host() == chrome::kChromeUISandboxHost
 #endif
