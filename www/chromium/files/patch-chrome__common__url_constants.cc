--- chrome/common/url_constants.cc.orig	2012-01-18 11:13:17.000000000 +0200
+++ chrome/common/url_constants.cc	2012-01-29 15:33:57.000000000 +0200
@@ -186,7 +186,7 @@
 const char kChromeUIScreenshotPath[] = "screenshots";
 const char kChromeUIThemePath[] = "theme";
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const char kChromeUILinuxProxyConfigHost[] = "linux-proxy-config";
 const char kChromeUISandboxHost[] = "sandbox";
 #endif
