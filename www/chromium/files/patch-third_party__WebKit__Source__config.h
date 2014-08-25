--- ./third_party/WebKit/Source/config.h.orig	2014-04-30 22:47:23.000000000 +0200
+++ ./third_party/WebKit/Source/config.h	2014-05-04 14:38:48.000000000 +0200
@@ -156,6 +156,6 @@
 #define SKIP_STATIC_CONSTRUCTORS_ON_GCC 1
 #endif
 
-#if OS(LINUX) || OS(ANDROID) || OS(WIN)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD) || OS(WIN)
 #define WTF_USE_HARFBUZZ 1
 #endif
