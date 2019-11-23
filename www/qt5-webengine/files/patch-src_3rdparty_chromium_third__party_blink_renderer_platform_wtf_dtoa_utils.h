--- src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/dtoa/utils.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/dtoa/utils.h
@@ -45,7 +45,7 @@
 // disabled.)
 // On Linux,x86 89255e-22 != Div_double(89255.0/1e22)
 #if defined(_M_X64) || defined(__x86_64__) || defined(__ARMEL__) || \
-    defined(__aarch64__) || defined(__MIPSEL__)
+    defined(__aarch64__) || defined(__MIPSEL__) || defined(__powerpc64__)
 #define DOUBLE_CONVERSION_CORRECT_DOUBLE_OPERATIONS 1
 #elif defined(_M_IX86) || defined(__i386__)
 #if defined(_WIN32)
