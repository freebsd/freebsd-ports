--- src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/rand/ctrdrbg.c.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/rand/ctrdrbg.c
@@ -70,8 +70,12 @@ OPENSSL_STATIC_ASSERT(CTR_DRBG_ENTROPY_LEN % AES_BLOCK
 // ctr_inc adds |n| to the last four bytes of |drbg->counter|, treated as a
 // big-endian number.
 static void ctr32_add(CTR_DRBG_STATE *drbg, uint32_t n) {
+#ifdef OPENSSL_BIGENDIAN
+  drbg->counter.words[3] += n;
+#else
   drbg->counter.words[3] =
       CRYPTO_bswap4(CRYPTO_bswap4(drbg->counter.words[3]) + n);
+#endif
 }
 
 static int ctr_drbg_update(CTR_DRBG_STATE *drbg, const uint8_t *data,
