--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2015-10-14 16:37:51.456856000 +0200
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc	2015-10-14 16:38:21.306588000 +0200
@@ -273,7 +273,7 @@
 #if !defined(OS_ANDROID)
           || url.host() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
           || url.host() == chrome::kChromeUILinuxProxyConfigHost ||
           url.host() == chrome::kChromeUISandboxHost
 #endif
