--- chrome/common/url_constants.h.orig	2011-09-10 15:16:51.000000000 +0300
+++ chrome/common/url_constants.h	2011-09-10 15:17:26.000000000 +0300
@@ -156,7 +156,7 @@
 extern const char kChromeUIThemePath[];
 extern const char kChromeUIThumbnailPath[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 extern const char kChromeUILinuxProxyConfigHost[];
 extern const char kChromeUISandboxHost[];
 #endif
