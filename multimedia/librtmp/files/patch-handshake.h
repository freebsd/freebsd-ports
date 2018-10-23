--- handshake.h.orig	2016-02-29 01:15:13 UTC
+++ handshake.h
@@ -69,9 +69,9 @@ typedef struct arcfour_ctx*	RC4_handle;
 #if OPENSSL_VERSION_NUMBER < 0x0090800 || !defined(SHA256_DIGEST_LENGTH)
 #error Your OpenSSL is too old, need 0.9.8 or newer with SHA256
 #endif
-#define HMAC_setup(ctx, key, len)	HMAC_CTX_init(&ctx); HMAC_Init_ex(&ctx, key, len, EVP_sha256(), 0)
-#define HMAC_crunch(ctx, buf, len)	HMAC_Update(&ctx, buf, len)
-#define HMAC_finish(ctx, dig, dlen)	HMAC_Final(&ctx, dig, &dlen); HMAC_CTX_cleanup(&ctx)
+#define HMAC_setup(ctx, key, len)	HMAC_Init_ex(ctx, key, len, EVP_sha256(), 0)
+#define HMAC_crunch(ctx, buf, len)	HMAC_Update(ctx, buf, len)
+#define HMAC_finish(ctx, dig, dlen)	HMAC_Final(ctx, dig, &dlen); HMAC_CTX_free(ctx)
 
 typedef RC4_KEY *	RC4_handle;
 #define RC4_alloc(h)	*h = malloc(sizeof(RC4_KEY))
@@ -117,7 +117,7 @@ static void InitRC4Encryption
 {
   uint8_t digest[SHA256_DIGEST_LENGTH];
   unsigned int digestLen = 0;
-  HMAC_CTX ctx;
+  HMAC_CTX *ctx = HMAC_CTX_new();
 
   RC4_alloc(rc4keyIn);
   RC4_alloc(rc4keyOut);
@@ -266,7 +266,7 @@ HMACsha256(const uint8_t *message, size_t messageLen, 
 	   size_t keylen, uint8_t *digest)
 {
   unsigned int digestLen;
-  HMAC_CTX ctx;
+  HMAC_CTX *ctx = HMAC_CTX_new();
 
   HMAC_setup(ctx, key, keylen);
   HMAC_crunch(ctx, message, messageLen);
