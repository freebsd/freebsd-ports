--- ./chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2014-04-30 22:42:10.000000000 +0200
+++ ./chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc	2014-05-04 14:38:46.000000000 +0200
@@ -473,7 +473,7 @@
       url.host() == chrome::kChromeUIMemoryRedirectHost ||
       url.host() == chrome::kChromeUIStatsHost ||
       url.host() == chrome::kChromeUITermsHost
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
       || url.host() == chrome::kChromeUILinuxProxyConfigHost
       || url.host() == chrome::kChromeUISandboxHost
 #endif
