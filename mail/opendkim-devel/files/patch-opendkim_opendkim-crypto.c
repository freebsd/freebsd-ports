--- opendkim/opendkim-crypto.c.orig	2022-12-30 01:52:49 UTC
+++ opendkim/opendkim-crypto.c
@@ -221,7 +221,7 @@ dkimf_crypto_free_id(void *ptr)
 	{
 		assert(pthread_setspecific(id_key, ptr) == 0);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER))
 		OPENSSL_thread_stop();
 #else
 		ERR_remove_state(0);
@@ -399,7 +399,7 @@ dkimf_crypto_free(void)
 {
 	if (crypto_init_done)
 	{
-#if OPENSSL_VERSION_NUMBER >= 0x10100000
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER))
 		OPENSSL_thread_stop();
 #else
 		CRYPTO_cleanup_all_ex_data();
