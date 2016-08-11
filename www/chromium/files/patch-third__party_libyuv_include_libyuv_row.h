--- third_party/libyuv/include/libyuv/row.h.orig	2016-06-16 21:03:47.000000000 +0200
+++ third_party/libyuv/include/libyuv/row.h	2016-06-26 15:14:58.000000000 +0200
@@ -160,10 +160,14 @@
 #define HAS_ARGBSHADEROW_SSE2
 #define HAS_ARGBSUBTRACTROW_SSE2
 #define HAS_ARGBUNATTENUATEROW_SSE2
+#if !(defined(__i386__) && defined(__GNUC__))
 #define HAS_BLENDPLANEROW_SSSE3
+#endif
 #define HAS_COMPUTECUMULATIVESUMROW_SSE2
 #define HAS_CUMULATIVESUMTOAVERAGEROW_SSE2
+#if !(defined(__i386__) && defined(__GNUC__))
 #define HAS_INTERPOLATEROW_SSSE3
+#endif
 #define HAS_RGBCOLORTABLEROW_X86
 #define HAS_SOBELROW_SSE2
 #define HAS_SOBELTOPLANEROW_SSE2
@@ -173,8 +177,7 @@
 
 // The following functions fail on gcc/clang 32 bit with fpic and framepointer.
 // caveat: clangcl uses row_win.cc which works.
-#if defined(NDEBUG) || !(defined(_DEBUG) && defined(__i386__)) || \
-    !defined(__i386__) || defined(_MSC_VER)
+#if !(defined(__i386__) && defined(__GNUC__))
 // TODO(fbarchard): fix build error on x86 debug
 // https://code.google.com/p/libyuv/issues/detail?id=524
 #define HAS_I411TOARGBROW_SSSE3
@@ -202,7 +205,7 @@
 #define HAS_COPYROW_AVX
 #define HAS_H422TOARGBROW_AVX2
 #define HAS_I400TOARGBROW_AVX2
-#if !(defined(_DEBUG) && defined(__i386__))
+#if !(defined(__i386__) && defined(__GNUC__))
 // TODO(fbarchard): fix build error on android_full_debug=1
 // https://code.google.com/p/libyuv/issues/detail?id=517
 #define HAS_I422ALPHATOARGBROW_AVX2
@@ -215,7 +218,9 @@
 #define HAS_I422TORGB565ROW_AVX2
 #define HAS_I422TORGBAROW_AVX2
 #define HAS_I444TOARGBROW_AVX2
+#if !(defined(__i386__) && defined(__GNUC__))
 #define HAS_INTERPOLATEROW_AVX2
+#endif
 #define HAS_J422TOARGBROW_AVX2
 #define HAS_MERGEUVROW_AVX2
 #define HAS_MIRRORROW_AVX2
@@ -238,8 +243,10 @@
 #define HAS_ARGBMULTIPLYROW_AVX2
 #define HAS_ARGBSUBTRACTROW_AVX2
 #define HAS_ARGBUNATTENUATEROW_AVX2
+#if !(defined(__i386__) && defined(__GNUC__))
 #define HAS_BLENDPLANEROW_AVX2
 #endif
+#endif
 
 // The following are available for AVX2 Visual C and clangcl 32 bit:
 // TODO(fbarchard): Port to gcc.
