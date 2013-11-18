--- third_party/WebKit/Source/config.h.orig	2013-11-08 07:50:10.000000000 +0100
+++ third_party/WebKit/Source/config.h	2013-11-15 16:58:16.000000000 +0100
@@ -181,6 +181,6 @@
 #define __STDC_FORMAT_MACROS 1
 #endif
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD)
 #define WTF_USE_HARFBUZZ 1
 #endif
