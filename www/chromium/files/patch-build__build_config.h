--- ./build/build_config.h.orig	2010-12-16 02:11:47.000000000 +0100
+++ ./build/build_config.h	2010-12-20 20:15:08.000000000 +0100
@@ -69,12 +69,12 @@
 #endif
 
 // Use tcmalloc
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(NO_TCMALLOC)
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(NO_TCMALLOC)
 #define USE_TCMALLOC 1
 #endif
 
 // Use heapchecker.
-#if defined(OS_LINUX) && !defined(NO_HEAPCHECKER)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(NO_HEAPCHECKER)
 #define USE_HEAPCHECKER 1
 #endif
 
