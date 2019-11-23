--- src/3rdparty/chromium/third_party/boringssl/src/crypto/poly1305/poly1305.c.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/poly1305/poly1305.c
@@ -32,10 +32,16 @@
 static uint32_t U8TO32_LE(const uint8_t *m) {
   uint32_t r;
   OPENSSL_memcpy(&r, m, sizeof(r));
+#ifdef OPENSSL_BIGENDIAN
+  r = CRYPTO_bswap4(r);
+#endif
   return r;
 }
 
 static void U32TO8_LE(uint8_t *m, uint32_t v) {
+#ifdef OPENSSL_BIGENDIAN
+  v = CRYPTO_bswap4(v);
+#endif
   OPENSSL_memcpy(m, &v, sizeof(v));
 }
 
