--- deps/VectorSimilarity/src/VecSim/spaces/space_includes.h.orig	2026-05-30 14:27:46 UTC
+++ deps/VectorSimilarity/src/VecSim/spaces/space_includes.h
@@ -17,6 +17,9 @@
 #ifdef CPU_FEATURES_ARCH_AARCH64
 #include "cpuinfo_aarch64.h"
 #endif // CPU_FEATURES_ARCH_AARCH64
+#ifdef CPU_FEATURES_ARCH_PPC
+#include "cpuinfo_ppc.h"
+#endif // CPU_FEATURES_ARCH_PPC
 
 #if defined(__AVX512F__) || defined(__AVX__) || defined(__SSE__)
 #if defined(__GNUC__)
