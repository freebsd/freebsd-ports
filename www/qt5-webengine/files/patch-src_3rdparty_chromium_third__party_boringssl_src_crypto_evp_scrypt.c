--- src/3rdparty/chromium/third_party/boringssl/src/crypto/evp/scrypt.c.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/evp/scrypt.c
@@ -196,9 +196,27 @@ int EVP_PBE_scrypt(const char *password, size_t passwo
     goto err;
   }
 
+#ifdef OPENSSL_BIGENDIAN
+  uint32_t *B32 = B->words;
+  size_t B_words = B_bytes >> 2;
+  do {
+    *B32 = CRYPTO_bswap4(*B32);
+    B32++;
+  } while(--B_words);
+#endif
+
   for (uint64_t i = 0; i < p; i++) {
     scryptROMix(B + 2 * r * i, r, N, T, V);
   }
+
+#ifdef OPENSSL_BIGENDIAN
+  B32 = B->words;
+  B_words = B_bytes >> 2;
+  do {
+    *B32 = CRYPTO_bswap4(*B32);
+    B32++;
+  } while(--B_words);
+#endif
 
   if (!PKCS5_PBKDF2_HMAC(password, password_len, (const uint8_t *)B, B_bytes, 1,
                          EVP_sha256(), key_len, out_key)) {
