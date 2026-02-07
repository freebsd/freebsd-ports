--- include/nfl/ops.hpp.orig	2023-07-24 21:30:23 UTC
+++ include/nfl/ops.hpp
@@ -281,18 +281,14 @@ struct _make_op<shoup<type, tag0>, expr<mulmod<type, t
 
 } // nfl
 
-#ifdef NFL_OPTIMIZED
-
 #include "nfl/opt/ops.hpp"
 
-#if defined __SSE4_2__ && defined NTT_SSE
+#if defined __SSE4_2__ && !defined __AVX2__
 #include "nfl/opt/arch/sse.hpp"
 #endif
 
-#if defined __AVX2__ && defined NTT_AVX2
+#if defined __AVX2__ && defined __SSE4_2__
 #include "nfl/opt/arch/avx2.hpp"
-#endif
-
 #endif
 
 #endif
