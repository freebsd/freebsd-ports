--- librtmp/hashswf.c.orig	2016-02-29 01:15:13 UTC
+++ librtmp/hashswf.c
@@ -37,10 +37,17 @@
 #define SHA256_DIGEST_LENGTH	32
 #endif
 #define HMAC_CTX	sha2_context
-#define HMAC_setup(ctx, key, len)	sha2_hmac_starts(&ctx, (unsigned char *)key, len, 0)
-#define HMAC_crunch(ctx, buf, len)	sha2_hmac_update(&ctx, buf, len)
-#define HMAC_finish(ctx, dig, dlen)	dlen = SHA256_DIGEST_LENGTH; sha2_hmac_finish(&ctx, dig)
-#define HMAC_close(ctx)
+#define HMAC_setup(ctx, key, len)	do { \
+		if (ctx == NULL) \
+			ctx = calloc(1, sizeof(*ctx)); \
+		sha2_hmac_starts(ctx, (unsigned char *)key, len, 0); \
+	} while (0);
+#define HMAC_crunch(ctx, buf, len)	sha2_hmac_update(ctx, buf, len)
+#define HMAC_finish(ctx, dig, dlen)	dlen = SHA256_DIGEST_LENGTH; sha2_hmac_finish(ctx, dig)
+#define HMAC_close(ctx)	do { \
+		free(ctx); \
+		ctx = NULL; \
+	} while (0)
 #elif defined(USE_GNUTLS)
 #include <nettle/hmac.h>
 #ifndef SHA256_DIGEST_LENGTH
@@ -48,19 +55,51 @@
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
 #else	/* USE_OPENSSL */
 #include <openssl/ssl.h>
 #include <openssl/sha.h>
 #include <openssl/hmac.h>
 #include <openssl/rc4.h>
-#define HMAC_setup(ctx, key, len)	HMAC_CTX_init(&ctx); HMAC_Init_ex(&ctx, (unsigned char *)key, len, EVP_sha256(), 0)
-#define HMAC_crunch(ctx, buf, len)	HMAC_Update(&ctx, (unsigned char *)buf, len)
-#define HMAC_finish(ctx, dig, dlen)	HMAC_Final(&ctx, (unsigned char *)dig, &dlen);
-#define HMAC_close(ctx)	HMAC_CTX_cleanup(&ctx)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#define HMAC_setup(ctx, key, len)	do { \
+		if (ctx == NULL) \
+			ctx = calloc(1, sizeof(*ctx)); \
+		HMAC_CTX_init(ctx); \
+		HMAC_Init_ex(ctx, (unsigned char *)key, len, EVP_sha256(), 0); \
+	} while (0)
+#else
+#define HMAC_setup(ctx, key, len)	do { \
+		if (ctx == NULL) \
+			ctx = HMAC_CTX_new(); \
+		HMAC_Init_ex(ctx, (unsigned char *)key, len, EVP_sha256(), 0); \
+	} while (0);
+#endif
+#define HMAC_crunch(ctx, buf, len)	HMAC_Update(ctx, (unsigned char *)buf, len)
+#define HMAC_finish(ctx, dig, dlen)	HMAC_Final(ctx, (unsigned char *)dig, &dlen);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#define HMAC_close(ctx)	do { \
+		HMAC_CTX_cleanup(ctx); \
+		free(ctx); \
+		ctx = NULL; \
+	} while (0)
+#else
+#define HMAC_close(ctx)	do { \
+		HMAC_CTX_reset(ctx); \
+		HMAC_CTX_free(ctx); \
+		ctx = NULL; \
+	} while (0)
+#endif
 #endif
 
 extern void RTMP_TLS_Init();
@@ -289,7 +328,7 @@ leave:
 struct info
 {
   z_stream *zs;
-  HMAC_CTX ctx;
+  HMAC_CTX *ctx;
   int first;
   int zlib;
   int size;
