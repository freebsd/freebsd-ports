--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2016-05-11 19:02:16 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -275,7 +275,7 @@ bool IsAboutUI(const GURL& url) {
 #if !defined(OS_ANDROID)
           || url.host() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
           || url.host() == chrome::kChromeUILinuxProxyConfigHost ||
           url.host() == chrome::kChromeUISandboxHost
 #endif
