--- librtmp/handshake.h.orig	2016-02-29 01:15:13 UTC
+++ librtmp/handshake.h
@@ -31,9 +31,13 @@
 #define SHA256_DIGEST_LENGTH	32
 #endif
 #define HMAC_CTX	sha2_context
-#define HMAC_setup(ctx, key, len)	sha2_hmac_starts(&ctx, (unsigned char *)key, len, 0)
-#define HMAC_crunch(ctx, buf, len)	sha2_hmac_update(&ctx, buf, len)
-#define HMAC_finish(ctx, dig, dlen)	dlen = SHA256_DIGEST_LENGTH; sha2_hmac_finish(&ctx, dig)
+#define HMAC_setup(ctx, key, len)	do { \
+		if (ctx == NULL) \
+			ctx = calloc(1, sizeof(*ctx)); \
+		sha2_hmac_starts(ctx, (unsigned char *)key, len, 0); \
+	} while (0)
+#define HMAC_crunch(ctx, buf, len)	sha2_hmac_update(ctx, buf, len)
+#define HMAC_finish(ctx, dig, dlen)	dlen = SHA256_DIGEST_LENGTH; sha2_hmac_finish(ctx, dig)
 
 typedef arc4_context *	RC4_handle;
 #define RC4_alloc(h)	*h = malloc(sizeof(arc4_context))
@@ -50,10 +54,17 @@ typedef arc4_context *	RC4_handle;
 #endif
 #undef HMAC_CTX
 #define HMAC_CTX	struct hmac_sha256_ctx
-#define HMAC_setup(ctx, key, len)	hmac_sha256_set_key(&ctx, len, key)
-#define HMAC_crunch(ctx, buf, len)	hmac_sha256_update(&ctx, len, buf)
-#define HMAC_finish(ctx, dig, dlen)	dlen = SHA256_DIGEST_LENGTH; hmac_sha256_digest(&ctx, SHA256_DIGEST_LENGTH, dig)
-#define HMAC_close(ctx)
+#define HMAC_setup(ctx, key, len)	do { \
+		if (ctx == NULL) \
+			ctx = calloc(1, sizeof(*ctx)); \
+		hmac_sha256_set_key(ctx, len, key); \
+	} while (0)
+#define HMAC_crunch(ctx, buf, len)	hmac_sha256_update(ctx, len, buf)
+#define HMAC_finish(ctx, dig, dlen)	dlen = SHA256_DIGEST_LENGTH; hmac_sha256_digest(ctx, SHA256_DIGEST_LENGTH, dig)
+#define HMAC_close(ctx)	do { \
+		free(ctx); \
+		ctx = NULL; \
+	} while (0)
 
 typedef struct arcfour_ctx*	RC4_handle;
 #define RC4_alloc(h)	*h = malloc(sizeof(struct arcfour_ctx))
@@ -69,9 +80,37 @@ typedef struct arcfour_ctx*	RC4_handle;
 #if OPENSSL_VERSION_NUMBER < 0x0090800 || !defined(SHA256_DIGEST_LENGTH)
 #error Your OpenSSL is too old, need 0.9.8 or newer with SHA256
 #endif
-#define HMAC_setup(ctx, key, len)	HMAC_CTX_init(&ctx); HMAC_Init_ex(&ctx, key, len, EVP_sha256(), 0)
-#define HMAC_crunch(ctx, buf, len)	HMAC_Update(&ctx, buf, len)
-#define HMAC_finish(ctx, dig, dlen)	HMAC_Final(&ctx, dig, &dlen); HMAC_CTX_cleanup(&ctx)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#define HMAC_setup(ctx, key, len)	do { \
+		if (ctx == NULL) \
+			ctx = calloc(1, sizeof(*ctx)); \
+		HMAC_CTX_init(ctx); \
+		HMAC_Init_ex(ctx, key, len, EVP_sha256(), 0); \
+	} while (0)
+#else
+#define HMAC_setup(ctx, key, len)	do { \
+		if (ctx == NULL) \
+			ctx = HMAC_CTX_new(); \
+		else \
+			HMAC_CTX_reset(ctx); \
+		HMAC_Init_ex(ctx, key, len, EVP_sha256(), 0); \
+	} while (0)
+#endif
+#define HMAC_crunch(ctx, buf, len)	HMAC_Update(ctx, buf, len)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#define HMAC_finish(ctx, dig, dlen)	do { \
+		HMAC_Final(ctx, dig, &dlen); \
+		HMAC_CTX_cleanup(ctx); \
+		free(ctx); \
+		ctx = NULL; \
+	} while (0)
+#else
+#define HMAC_finish(ctx, dig, dlen)	do { \
+		HMAC_Final(ctx, dig, &dlen); \
+		HMAC_CTX_free(ctx); \
+		ctx = NULL; \
+	} while (0)
+#endif
 
 typedef RC4_KEY *	RC4_handle;
 #define RC4_alloc(h)	*h = malloc(sizeof(RC4_KEY))
@@ -117,7 +156,7 @@ static void InitRC4Encryption
 {
   uint8_t digest[SHA256_DIGEST_LENGTH];
   unsigned int digestLen = 0;
-  HMAC_CTX ctx;
+  HMAC_CTX *ctx = NULL;
 
   RC4_alloc(rc4keyIn);
   RC4_alloc(rc4keyOut);
@@ -266,7 +305,7 @@ HMACsha256(const uint8_t *message, size_
 	   size_t keylen, uint8_t *digest)
 {
   unsigned int digestLen;
-  HMAC_CTX ctx;
+  HMAC_CTX *ctx = NULL;
 
   HMAC_setup(ctx, key, keylen);
   HMAC_crunch(ctx, message, messageLen);
