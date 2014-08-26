--- ./third_party/WebKit/Source/config.h.orig	2014-08-20 21:08:07.000000000 +0200
+++ ./third_party/WebKit/Source/config.h	2014-08-22 15:06:26.000000000 +0200
@@ -155,6 +155,6 @@
 #define SKIP_STATIC_CONSTRUCTORS_ON_GCC 1
 #endif
 
-#if OS(LINUX) || OS(ANDROID) || OS(WIN)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD) || OS(WIN)
 #define WTF_USE_HARFBUZZ 1
 #endif
