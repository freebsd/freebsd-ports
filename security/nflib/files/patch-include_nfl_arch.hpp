--- include/nfl/arch.hpp.orig	2023-07-24 21:28:33 UTC
+++ include/nfl/arch.hpp
@@ -3,14 +3,10 @@
 
 #include "nfl/arch/common.hpp"
 
-#ifdef NFL_OPTIMIZED
-
-#if defined __AVX2__ && defined NTT_AVX2
+#if defined __AVX2__ && defined __SSE4_2__
 #define CC_SIMD nfl::simd::avx2
-#elif defined __SSE4_2__ && defined NTT_SSE
+#elif defined __SSE4_2__ && !defined __AVX2__
 #define CC_SIMD nfl::simd::sse
-#endif
-
 #endif
 
 #ifndef CC_SIMD
