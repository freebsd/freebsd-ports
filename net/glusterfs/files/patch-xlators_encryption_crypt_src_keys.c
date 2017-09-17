--- xlators/encryption/crypt/src/keys.c.orig	2017-02-25 14:37:16 UTC
+++ xlators/encryption/crypt/src/keys.c
@@ -113,7 +113,7 @@ static int32_t kderive_init(struct kderi
 static void kderive_update(struct kderive_context *ctx)
 {
 	uint32_t i;
-#if (OPENSSL_VERSION_NUMBER < 0x1010002f)
+#if (OPENSSL_VERSION_NUMBER < 0x1010002f) || defined(LIBRESSL_VERSION_NUMBER)
 	HMAC_CTX hctx;
 #endif
         HMAC_CTX *phctx = NULL;
@@ -123,7 +123,7 @@ static void kderive_update(struct kderiv
 
 	check_prf_iters(num_iters);
 
-#if (OPENSSL_VERSION_NUMBER < 0x1010002f)
+#if (OPENSSL_VERSION_NUMBER < 0x1010002f) || defined(LIBRESSL_VERSION_NUMBER)
 	HMAC_CTX_init(&hctx);
         phctx = &hctx;
 #else
@@ -144,7 +144,7 @@ static void kderive_update(struct kderiv
 
 		pos += PRF_OUTPUT_SIZE;
 	}
-#if (OPENSSL_VERSION_NUMBER < 0x1010002f)
+#if (OPENSSL_VERSION_NUMBER < 0x1010002f) || defined(LIBRESSL_VERSION_NUMBER)
 	HMAC_CTX_cleanup(phctx);
 #else
         HMAC_CTX_free(phctx);
