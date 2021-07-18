--- third_party/libgav1/src/src/utils/entropy_decoder.cc.orig	2021-04-22 09:28:56 UTC
+++ third_party/libgav1/src/src/utils/entropy_decoder.cc
@@ -33,7 +33,7 @@
 #include <arm_neon.h>
 #endif
 
-#if defined(__SSE2__) || defined(LIBGAV1_X86_MSVC)
+#if (defined(__SSE2__) || defined(LIBGAV1_X86_MSVC)) && !defined(__FreeBSD__)
 #define LIBGAV1_ENTROPY_DECODER_ENABLE_SSE2 1
 #else
 #define LIBGAV1_ENTROPY_DECODER_ENABLE_SSE2 0
