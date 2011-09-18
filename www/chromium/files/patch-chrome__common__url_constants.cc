--- chrome/common/url_constants.cc.orig	2011-09-10 15:16:44.000000000 +0300
+++ chrome/common/url_constants.cc	2011-09-10 15:17:50.000000000 +0300
@@ -158,7 +158,7 @@
 const char kChromeUIThemePath[] = "theme";
 const char kChromeUIThumbnailPath[] = "thumb";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 const char kChromeUILinuxProxyConfigHost[] = "linux-proxy-config";
 const char kChromeUISandboxHost[] = "sandbox";
 #endif
