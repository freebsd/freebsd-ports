--- third_party/libyuv/include/libyuv/row.h.orig	2016-05-11 19:03:40 UTC
+++ third_party/libyuv/include/libyuv/row.h
@@ -201,7 +201,7 @@ extern "C" {
 #define HAS_COPYROW_AVX
 #define HAS_H422TOARGBROW_AVX2
 #define HAS_I400TOARGBROW_AVX2
-#if !(defined(_DEBUG) && defined(__i386__))
+#if !(defined(__i386__) && defined(__GNUC__))
 // TODO(fbarchard): fix build error on android_full_debug=1
 // https://code.google.com/p/libyuv/issues/detail?id=517
 #define HAS_I422ALPHATOARGBROW_AVX2
