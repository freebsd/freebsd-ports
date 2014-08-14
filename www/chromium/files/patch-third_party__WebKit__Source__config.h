--- ./third_party/WebKit/Source/config.h.orig	2014-08-12 21:07:17.000000000 +0200
+++ ./third_party/WebKit/Source/config.h	2014-08-13 09:56:58.000000000 +0200
@@ -156,6 +156,6 @@
 #define SKIP_STATIC_CONSTRUCTORS_ON_GCC 1
 #endif
 
-#if OS(LINUX) || OS(ANDROID) || OS(WIN)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD) || OS(WIN)
 #define WTF_USE_HARFBUZZ 1
 #endif
