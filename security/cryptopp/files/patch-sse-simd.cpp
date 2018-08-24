Fix build without SIMD on FreeBSD 10.x

--- sse-simd.cpp.orig	2018-04-08 08:47:12 UTC
+++ sse-simd.cpp
@@ -23,7 +23,7 @@
 #endif
 
 // Needed by SunCC and MSVC
-#if (CRYPTOPP_BOOL_X86 || CRYPTOPP_BOOL_X32 || CRYPTOPP_BOOL_X64)
+#if (CRYPTOPP_BOOL_X86 || CRYPTOPP_BOOL_X32 || CRYPTOPP_BOOL_X64) && defined(CRYPTOPP_SSE2_ASM_AVAILABLE)
 # include <emmintrin.h>
 #endif
 
