--- build/build_config.h.orig	2012-03-24 09:01:53.000000000 +0200
+++ build/build_config.h	2012-03-28 00:55:12.000000000 +0300
@@ -67,7 +67,7 @@
 #endif
 
 // Use tcmalloc
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(NO_TCMALLOC)
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(NO_TCMALLOC)
 #define USE_TCMALLOC 1
 #endif
 
