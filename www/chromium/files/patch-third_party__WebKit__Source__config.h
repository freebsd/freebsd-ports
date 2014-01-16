--- third_party/WebKit/Source/config.h.orig	2013-11-08 07:50:10.000000000 +0100
+++ third_party/WebKit/Source/config.h	2013-11-15 16:58:16.000000000 +0100
@@ -167,6 +167,6 @@
 #define __STDC_FORMAT_MACROS 1
 #endif
 
-#if OS(LINUX) || OS(ANDROID) || ENABLE(HARFBUZZ_ON_WINDOWS)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD) || ENABLE(HARFBUZZ_ON_WINDOWS)
 #define WTF_USE_HARFBUZZ 1
 #endif
