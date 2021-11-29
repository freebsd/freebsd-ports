--- openMVG/matching/metric_simd.hpp.orig	2021-11-29 11:14:30 UTC
+++ openMVG/matching/metric_simd.hpp
@@ -17,7 +17,9 @@
 #include <numeric>
 
 #include <cstdint>
+#if defined(__amd64__) || defined(__i386__)
 #include <immintrin.h>
+#endif
 
 namespace openMVG {
 namespace matching {
