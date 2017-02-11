--- src/eng_back.c.orig	2017-01-26 21:19:45 UTC
+++ src/eng_back.c
@@ -49,7 +49,7 @@ struct st_engine_ctx {
 	char *init_args;
 
 	/* Engine initialization mutex */
-#if OPENSSL_VERSION_NUMBER >= 0x10100004L
+#if OPENSSL_VERSION_NUMBER >= 0x10100004L && !defined(LIBRESSL_VERSION_NUMBER)
 	CRYPTO_RWLOCK *rwlock;
 #else
 	int rwlock;
@@ -206,7 +206,7 @@ ENGINE_CTX *ctx_new()
 #endif
 	}
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100004L
+#if OPENSSL_VERSION_NUMBER >= 0x10100004L && !defined(LIBRESSL_VERSION_NUMBER)
 	ctx->rwlock = CRYPTO_THREAD_lock_new();
 #else
 	ctx->rwlock = CRYPTO_get_dynlock_create_callback() ?
@@ -224,7 +224,7 @@ int ctx_destroy(ENGINE_CTX *ctx)
 		ctx_destroy_pin(ctx);
 		OPENSSL_free(ctx->module);
 		OPENSSL_free(ctx->init_args);
-#if OPENSSL_VERSION_NUMBER >= 0x10100004L
+#if OPENSSL_VERSION_NUMBER >= 0x10100004L && !defined(LIBRESSL_VERSION_NUMBER)
 		CRYPTO_THREAD_lock_free(ctx->rwlock);
 #else
 		if (ctx->rwlock)
@@ -274,7 +274,7 @@ static void ctx_init_libp11_unlocked(ENG
 
 static int ctx_init_libp11(ENGINE_CTX *ctx)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100004L
+#if OPENSSL_VERSION_NUMBER >= 0x10100004L && !defined(LIBRESSL_VERSION_NUMBER)
 	CRYPTO_THREAD_write_lock(ctx->rwlock);
 #else
 	if (ctx->rwlock)
@@ -282,7 +282,7 @@ static int ctx_init_libp11(ENGINE_CTX *c
 #endif
 	if (ctx->pkcs11_ctx == NULL || ctx->slot_list == NULL)
 		ctx_init_libp11_unlocked(ctx);
-#if OPENSSL_VERSION_NUMBER >= 0x10100004L
+#if OPENSSL_VERSION_NUMBER >= 0x10100004L && !defined(LIBRESSL_VERSION_NUMBER)
 	CRYPTO_THREAD_unlock(ctx->rwlock);
 #else
 	if (ctx->rwlock)
@@ -302,7 +302,7 @@ int ctx_init(ENGINE_CTX *ctx)
 	/* Only attempt initialization when dynamic locks are unavailable.
 	 * This likely also indicates a single-threaded application,
 	 * so temporarily unlocking CRYPTO_LOCK_ENGINE should be safe. */
-#if OPENSSL_VERSION_NUMBER < 0x10100004L
+#if OPENSSL_VERSION_NUMBER < 0x10100004L && !defined(LIBRESSL_VERSION_NUMBER)
 	if (CRYPTO_get_dynlock_create_callback() == NULL ||
 			CRYPTO_get_dynlock_lock_callback() == NULL ||
 			CRYPTO_get_dynlock_destroy_callback() == NULL) {
