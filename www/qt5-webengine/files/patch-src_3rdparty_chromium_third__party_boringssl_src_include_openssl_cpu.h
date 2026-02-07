--- src/3rdparty/chromium/third_party/boringssl/src/include/openssl/cpu.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/include/openssl/cpu.h
@@ -105,7 +105,7 @@ static inline const uint32_t *OPENSSL_ia32cap_get(void
 
 #if defined(OPENSSL_ARM) || defined(OPENSSL_AARCH64)
 
-#if defined(OPENSSL_APPLE)
+#if defined(OPENSSL_APPLE) || defined(__FreeBSD__)
 // iOS builds use the static ARM configuration.
 #define OPENSSL_STATIC_ARMCAP
 #endif
