--- ./base/debug/leak_annotations.h.orig	2010-12-16 02:11:48.000000000 +0100
+++ ./base/debug/leak_annotations.h	2010-12-20 20:15:07.000000000 +0100
@@ -8,7 +8,7 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) && defined(USE_HEAPCHECKER)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && defined(USE_HEAPCHECKER)
 
 #include "third_party/tcmalloc/chromium/src/google/heap-checker.h"
 
