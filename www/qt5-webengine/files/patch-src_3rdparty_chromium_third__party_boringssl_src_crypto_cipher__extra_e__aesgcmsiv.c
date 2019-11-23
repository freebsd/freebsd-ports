--- src/3rdparty/chromium/third_party/boringssl/src/crypto/cipher_extra/e_aesgcmsiv.c.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/cipher_extra/e_aesgcmsiv.c
@@ -625,7 +625,11 @@ static void gcm_siv_crypt(uint8_t *out, const uint8_t 
   for (size_t done = 0; done < in_len;) {
     uint8_t keystream[AES_BLOCK_SIZE];
     enc_block(counter.c, keystream, key);
+#ifdef OPENSSL_BIGENDIAN
+    counter.w[0] = CRYPTO_bswap4(CRYPTO_bswap4(counter.w[0]) + 1);
+#else
     counter.w[0]++;
+#endif
 
     size_t todo = AES_BLOCK_SIZE;
     if (in_len - done < todo) {
@@ -673,8 +677,13 @@ static void gcm_siv_polyval(
     } bitlens;
   } length_block;
 
+#ifdef OPENSSL_BIGENDIAN
+  length_block.bitlens.ad = CRYPTO_bswap8(ad_len * 8);
+  length_block.bitlens.in = CRYPTO_bswap8(in_len * 8);
+#else
   length_block.bitlens.ad = ad_len * 8;
   length_block.bitlens.in = in_len * 8;
+#endif
   CRYPTO_POLYVAL_update_blocks(&polyval_ctx, length_block.c,
                                sizeof(length_block));
 
