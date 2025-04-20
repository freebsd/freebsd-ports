--- src/lib/geogram/basic/algorithm.h.orig	2024-06-14 05:04:18 UTC
+++ src/lib/geogram/basic/algorithm.h
@@ -42,7 +42,7 @@
 
 #include <geogram/basic/common.h>
 
-#if defined(GEO_OS_LINUX) && defined(GEO_OPENMP)
+#if (defined(GEO_OS_LINUX) || defined(GEO_OS_FREEBSD)) && defined(GEO_OPENMP)
 #if (__GNUC__ >= 4) && (__GNUC_MINOR__ >= 4) && !defined(GEO_OS_ANDROID)
 #include <parallel/algorithm>
 #define GEO_USE_GCC_PARALLEL_STL
