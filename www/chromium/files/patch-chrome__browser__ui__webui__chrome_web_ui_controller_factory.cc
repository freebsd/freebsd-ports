--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2015-10-13 15:04:32.000000000 -0400
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc	2015-10-14 08:16:21.359565000 -0400
@@ -273,7 +273,7 @@
 #if !defined(OS_ANDROID)
           || url.host() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
           || url.host() == chrome::kChromeUILinuxProxyConfigHost ||
           url.host() == chrome::kChromeUISandboxHost
 #endif
