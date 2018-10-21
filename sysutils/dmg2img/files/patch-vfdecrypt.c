--- vfdecrypt.c.orig	2010-03-24 17:52:45 UTC
+++ vfdecrypt.c
@@ -183,7 +183,11 @@ void adjust_v2_header_byteorder(cencrypt
   pwhdr->encrypted_keyblob_size = htonl(pwhdr->encrypted_keyblob_size);
 }
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+HMAC_CTX *hmacsha1_ctx = NULL;
+#else
 HMAC_CTX hmacsha1_ctx;
+#endif
 AES_KEY aes_decrypt_key;
 int CHUNK_SIZE=4096;  // default
 
@@ -196,9 +200,15 @@ void compute_iv(uint32_t chunk_no, uint8
   unsigned int mdLen;
   
   chunk_no = OSSwapHostToBigInt32(chunk_no);
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  HMAC_Init_ex(hmacsha1_ctx, NULL, 0, NULL, NULL);
+  HMAC_Update(hmacsha1_ctx, (void *) &chunk_no, sizeof(uint32_t));
+  HMAC_Final(hmacsha1_ctx, mdResult, &mdLen);
+#else
   HMAC_Init_ex(&hmacsha1_ctx, NULL, 0, NULL, NULL);
   HMAC_Update(&hmacsha1_ctx, (void *) &chunk_no, sizeof(uint32_t));
   HMAC_Final(&hmacsha1_ctx, mdResult, &mdLen);
+#endif
   memcpy(iv, mdResult, CIPHER_BLOCKSIZE);
 }
 
@@ -212,47 +222,84 @@ void decrypt_chunk(uint8_t *ctext, uint8
 /* DES3-EDE unwrap operation loosely based on to RFC 2630, section 12.6 
  *    wrapped_key has to be 40 bytes in length.  */
 int apple_des3_ede_unwrap_key(uint8_t *wrapped_key, int wrapped_key_len, uint8_t *decryptKey, uint8_t *unwrapped_key) {
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  EVP_CIPHER_CTX *ctx = NULL;
+#else
   EVP_CIPHER_CTX ctx;
+#endif
   uint8_t *TEMP1, *TEMP2, *CEKICV;
   uint8_t IV[8] = { 0x4a, 0xdd, 0xa2, 0x2c, 0x79, 0xe8, 0x21, 0x05 };
   int outlen, tmplen, i;
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  ctx = EVP_CIPHER_CTX_new();
+#else
   EVP_CIPHER_CTX_init(&ctx);
+#endif
   /* result of the decryption operation shouldn't be bigger than ciphertext */
   TEMP1 = malloc(wrapped_key_len);
   TEMP2 = malloc(wrapped_key_len);
   CEKICV = malloc(wrapped_key_len);
   /* uses PKCS#7 padding for symmetric key operations by default */
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  EVP_DecryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, decryptKey, IV);
+  if(!EVP_DecryptUpdate(ctx, TEMP1, &outlen, wrapped_key, wrapped_key_len)) {
+#else
   EVP_DecryptInit_ex(&ctx, EVP_des_ede3_cbc(), NULL, decryptKey, IV);
-
   if(!EVP_DecryptUpdate(&ctx, TEMP1, &outlen, wrapped_key, wrapped_key_len)) {
+#endif
     fprintf(stderr, "internal error (1) during key unwrap operation!\n");
     return(-1);
   }
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  if(!EVP_DecryptFinal_ex(ctx, TEMP1 + outlen, &tmplen)) {
+#else
   if(!EVP_DecryptFinal_ex(&ctx, TEMP1 + outlen, &tmplen)) {
+#endif
     fprintf(stderr, "internal error (2) during key unwrap operation!\n");
     return(-1);
   }
   outlen += tmplen;
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  EVP_CIPHER_CTX_free(ctx);
+#else
   EVP_CIPHER_CTX_cleanup(&ctx);
+#endif
 
   /* reverse order of TEMP3 */
   for(i = 0; i < outlen; i++) TEMP2[i] = TEMP1[outlen - i - 1];
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  ctx = EVP_CIPHER_CTX_new();
+#else
   EVP_CIPHER_CTX_init(&ctx);
+#endif
   /* uses PKCS#7 padding for symmetric key operations by default */
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  EVP_DecryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, decryptKey, TEMP2);
+  if(!EVP_DecryptUpdate(ctx, CEKICV, &outlen, TEMP2+8, outlen-8)) {
+#else
   EVP_DecryptInit_ex(&ctx, EVP_des_ede3_cbc(), NULL, decryptKey, TEMP2);
   if(!EVP_DecryptUpdate(&ctx, CEKICV, &outlen, TEMP2+8, outlen-8)) {
+#endif
     fprintf(stderr, "internal error (3) during key unwrap operation!\n");
     return(-1);
   }
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  if(!EVP_DecryptFinal_ex(ctx, CEKICV + outlen, &tmplen)) {
+#else
   if(!EVP_DecryptFinal_ex(&ctx, CEKICV + outlen, &tmplen)) {
+#endif
     fprintf(stderr, "internal error (4) during key unwrap operation!\n");
     return(-1);
   }
 
   outlen += tmplen;
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  EVP_CIPHER_CTX_free(ctx);
+#else
   EVP_CIPHER_CTX_cleanup(&ctx);
+#endif
 
   memcpy(unwrapped_key, CEKICV+4, outlen-4);
   free(TEMP1);
@@ -279,7 +326,11 @@ int unwrap_v1_header(char *passphrase, c
 int unwrap_v2_header(char *passphrase, cencrypted_v2_pwheader *header, uint8_t *aes_key, uint8_t *hmacsha1_key) {
   /* derived key is a 3DES-EDE key */
   uint8_t derived_key[192/8];
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  EVP_CIPHER_CTX *ctx = NULL;
+#else
   EVP_CIPHER_CTX ctx;
+#endif
   uint8_t *TEMP1;
   int outlen, tmplen;
 
@@ -288,22 +339,40 @@ int unwrap_v2_header(char *passphrase, c
 
   print_hex(derived_key, 192/8);
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  ctx = EVP_CIPHER_CTX_new();
+#else
   EVP_CIPHER_CTX_init(&ctx);
+#endif
   /* result of the decryption operation shouldn't be bigger than ciphertext */
   TEMP1 = malloc(header->encrypted_keyblob_size);
   /* uses PKCS#7 padding for symmetric key operations by default */
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  EVP_DecryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, derived_key, header->blob_enc_iv);
+
+  if(!EVP_DecryptUpdate(ctx, TEMP1, &outlen, header->encrypted_keyblob, header->encrypted_keyblob_size)) {
+#else
   EVP_DecryptInit_ex(&ctx, EVP_des_ede3_cbc(), NULL, derived_key, header->blob_enc_iv);
 
   if(!EVP_DecryptUpdate(&ctx, TEMP1, &outlen, header->encrypted_keyblob, header->encrypted_keyblob_size)) {
+#endif
     fprintf(stderr, "internal error (1) during key unwrap operation!\n");
     return(-1);
   }
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  if(!EVP_DecryptFinal_ex(ctx, TEMP1 + outlen, &tmplen)) {
+#else
   if(!EVP_DecryptFinal_ex(&ctx, TEMP1 + outlen, &tmplen)) {
+#endif
     fprintf(stderr, "internal error (2) during key unwrap operation!\n");
     return(-1);
   }
   outlen += tmplen;
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  EVP_CIPHER_CTX_free(ctx);
+#else
   EVP_CIPHER_CTX_cleanup(&ctx);
+#endif
   memcpy(aes_key, TEMP1, 16);
   memcpy(hmacsha1_key, TEMP1, 20);
 
@@ -446,8 +515,14 @@ int main(int argc, char *argv[]) {
     CHUNK_SIZE = v2header.blocksize;
   }
   
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  hmacsha1_ctx = HMAC_CTX_new();
+  HMAC_CTX_reset(hmacsha1_ctx);
+  HMAC_Init_ex(hmacsha1_ctx, hmacsha1_key, sizeof(hmacsha1_key), EVP_sha1(), NULL);
+#else
   HMAC_CTX_init(&hmacsha1_ctx);
   HMAC_Init_ex(&hmacsha1_ctx, hmacsha1_key, sizeof(hmacsha1_key), EVP_sha1(), NULL);
+#endif
   AES_set_decrypt_key(aes_key, CIPHER_KEY_LENGTH * 8, &aes_decrypt_key);
   
   if (verbose >= 1) {
