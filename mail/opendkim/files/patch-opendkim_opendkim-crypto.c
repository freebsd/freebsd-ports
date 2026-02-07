--- opendkim/opendkim-crypto.c.orig	2013-02-25 21:02:41 UTC
+++ opendkim/opendkim-crypto.c
@@ -222,7 +222,11 @@ dkimf_crypto_free_id(void *ptr)
 	{
 		assert(pthread_setspecific(id_key, ptr) == 0);
 
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER))
+		OPENSSL_thread_stop();
+#else
 		ERR_remove_state(0);
+#endif
 
 		free(ptr);
 
@@ -392,11 +396,15 @@ dkimf_crypto_free(void)
 {
 	if (crypto_init_done)
 	{
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER))
+		OPENSSL_thread_stop();
+#else
 		CRYPTO_cleanup_all_ex_data();
 		CONF_modules_free();
 		EVP_cleanup();
 		ERR_free_strings();
 		ERR_remove_state(0);
+#endif
 
 		if (nmutexes > 0)
 		{
