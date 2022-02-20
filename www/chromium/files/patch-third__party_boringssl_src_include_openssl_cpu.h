--- third_party/boringssl/src/include/openssl/cpu.h.orig	2022-02-07 13:39:41 UTC
+++ third_party/boringssl/src/include/openssl/cpu.h
@@ -105,7 +105,7 @@ OPENSSL_INLINE const uint32_t *OPENSSL_ia32cap_get(voi
 
 #if defined(OPENSSL_ARM) || defined(OPENSSL_AARCH64)
 
-#if defined(OPENSSL_APPLE)
+#if defined(OPENSSL_APPLE) || defined(OPENSSL_OPENBSD)
 // iOS builds use the static ARM configuration.
 #define OPENSSL_STATIC_ARMCAP
 #endif
