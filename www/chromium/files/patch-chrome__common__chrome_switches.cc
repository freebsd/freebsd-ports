--- ./chrome/common/chrome_switches.cc.orig	2010-12-16 02:12:13.000000000 +0100
+++ ./chrome/common/chrome_switches.cc	2010-12-20 20:15:08.000000000 +0100
@@ -1273,7 +1273,7 @@
 const char kEnableAdvancedFileSystem[]      = "enable-advanced-fs";
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Specify the amount the trackpad should scroll by.
 const char kScrollPixels[]                  = "scroll-pixels";
 #endif
