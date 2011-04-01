--- ./chrome/common/chrome_switches.h.orig	2010-12-16 02:12:13.000000000 +0100
+++ ./chrome/common/chrome_switches.h	2010-12-20 20:15:08.000000000 +0100
@@ -361,7 +361,7 @@
 extern const char kEnableAdvancedFileSystem[];
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 extern const char kScrollPixels[];
 #endif
 
