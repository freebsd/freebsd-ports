--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2017-03-09 20:04:29 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -289,7 +289,7 @@ bool IsAboutUI(const GURL& url) {
 #if !defined(OS_ANDROID)
           || url.host_piece() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
           || url.host_piece() == chrome::kChromeUILinuxProxyConfigHost ||
           url.host_piece() == chrome::kChromeUISandboxHost
 #endif
