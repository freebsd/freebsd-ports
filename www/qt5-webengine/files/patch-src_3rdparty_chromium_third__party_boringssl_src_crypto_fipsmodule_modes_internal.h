--- src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/modes/internal.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/modes/internal.h
@@ -70,11 +70,17 @@ extern "C" {
 static inline uint32_t GETU32(const void *in) {
   uint32_t v;
   OPENSSL_memcpy(&v, in, sizeof(v));
+#ifdef OPENSSL_BIGENDIAN
+  return v;
+#else
   return CRYPTO_bswap4(v);
+#endif
 }
 
 static inline void PUTU32(void *out, uint32_t v) {
+#ifndef OPENSSL_BIGENDIAN
   v = CRYPTO_bswap4(v);
+#endif
   OPENSSL_memcpy(out, &v, sizeof(v));
 }
 
