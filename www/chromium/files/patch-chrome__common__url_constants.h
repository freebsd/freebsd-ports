--- chrome/common/url_constants.h.orig	2012-01-18 11:13:17.000000000 +0200
+++ chrome/common/url_constants.h	2012-01-29 15:35:17.000000000 +0200
@@ -178,7 +178,7 @@
 extern const char kChromeUIScreenshotPath[];
 extern const char kChromeUIThemePath[];
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kChromeUILinuxProxyConfigHost[];
 extern const char kChromeUISandboxHost[];
 #endif
