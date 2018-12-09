--- src/lib/geogram/basic/algorithm.h.orig	2018-12-09 17:43:13 UTC
+++ src/lib/geogram/basic/algorithm.h
@@ -48,7 +48,7 @@
 
 #include <geogram/basic/common.h>
 
-#if defined(GEO_OS_LINUX) && defined(GEO_OPENMP)
+#if (defined(GEO_OS_LINUX) || defined(GEO_OS_FREEBSD)) && defined(GEO_OPENMP)
 #if (__GNUC__ >= 4) && (__GNUC_MINOR__ >= 4) && !defined(GEO_OS_ANDROID)
 #include <parallel/algorithm>
 #define GEO_USE_GCC_PARALLEL_STL
