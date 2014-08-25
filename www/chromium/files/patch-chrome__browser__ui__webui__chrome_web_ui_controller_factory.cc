--- ./chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2014-08-20 21:02:03.000000000 +0200
+++ ./chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc	2014-08-22 15:06:25.000000000 +0200
@@ -493,7 +493,7 @@
       url.host() == chrome::kChromeUIMemoryRedirectHost ||
       url.host() == chrome::kChromeUIStatsHost ||
       url.host() == chrome::kChromeUITermsHost
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
       || url.host() == chrome::kChromeUILinuxProxyConfigHost
       || url.host() == chrome::kChromeUISandboxHost
 #endif
