--- third_party/libyuv/include/libyuv/row.h.orig	2016-01-22 20:34:30.817629081 +0100
+++ third_party/libyuv/include/libyuv/row.h	2016-01-22 21:28:33.325381305 +0100
@@ -197,7 +199,7 @@
 #define HAS_COPYROW_AVX
 #define HAS_H422TOARGBROW_AVX2
 #define HAS_I400TOARGBROW_AVX2
-#if !(defined(_DEBUG) && defined(__i386__))
+#if !(defined(__i386__) && defined(__GNUC__))
 // TODO(fbarchard): fix build error on android_full_debug=1
 // https://code.google.com/p/libyuv/issues/detail?id=517
 #define HAS_I422ALPHATOARGBROW_AVX2
