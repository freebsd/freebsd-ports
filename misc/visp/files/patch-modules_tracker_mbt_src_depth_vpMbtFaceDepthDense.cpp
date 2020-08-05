From https://github.com/lagadic/visp/issues/783#issuecomment-653403417

--- modules/tracker/mbt/src/depth/vpMbtFaceDepthDense.cpp.orig	2020-08-05 18:31:46 UTC
+++ modules/tracker/mbt/src/depth/vpMbtFaceDepthDense.cpp
@@ -36,6 +36,10 @@
 #include <visp3/core/vpCPUFeatures.h>
 #include <visp3/mbt/vpMbtFaceDepthDense.h>
 
+#ifdef VISP_HAVE_PCL
+#include <pcl/common/point_tests.h>
+#endif
+
 #if defined __SSE2__ || defined _M_X64 || (defined _M_IX86_FP && _M_IX86_FP >= 2)
 #include <emmintrin.h>
 #define VISP_HAVE_SSE2 1
