--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -290,7 +290,7 @@ bool IsAboutUI(const GURL& url) {
 #if !defined(OS_ANDROID)
           || url.host_piece() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
           || url.host_piece() == chrome::kChromeUILinuxProxyConfigHost ||
           url.host_piece() == chrome::kChromeUISandboxHost
 #endif
