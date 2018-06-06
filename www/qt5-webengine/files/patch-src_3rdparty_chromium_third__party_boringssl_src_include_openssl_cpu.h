--- src/3rdparty/chromium/third_party/boringssl/src/include/openssl/cpu.h.orig	2018-03-21 07:29:16 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/include/openssl/cpu.h
@@ -95,7 +95,7 @@ extern uint32_t OPENSSL_ia32cap_P[4];
 
 #if defined(OPENSSL_ARM) || defined(OPENSSL_AARCH64)
 
-#if defined(OPENSSL_APPLE)
+#if defined(OPENSSL_APPLE) || defined(__FreeBSD__)
 /* iOS builds use the static ARM configuration. */
 #define OPENSSL_STATIC_ARMCAP
 #endif
