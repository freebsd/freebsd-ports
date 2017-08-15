--- winpr/libwinpr/utils/ssl.c.orig	2017-07-24 08:46:54 UTC
+++ winpr/libwinpr/utils/ssl.c
@@ -58,7 +58,7 @@ struct CRYPTO_dynlock_value
 };
 
 
-#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L) || defined(LIBRESSL_VERSION_NUMBER)
 static unsigned long _winpr_openssl_id(void)
 {
 	return (unsigned long)GetCurrentThreadId();
@@ -172,7 +172,7 @@ static BOOL _winpr_openssl_initialize_locking(void)
 	}
 
 	/* Use the deprecated CRYPTO_get_id_callback() if building against OpenSSL < 1.0.0 */
-#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L) || defined(LIBRESSL_VERSION_NUMBER)
 
 	if (CRYPTO_get_id_callback())
 	{
@@ -222,7 +222,7 @@ static BOOL _winpr_openssl_cleanup_locking(void)
 		CRYPTO_set_dynlock_destroy_callback(NULL);
 	}
 
-#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L) || defined(LIBRESSL_VERSION_NUMBER)
 
 	if (CRYPTO_get_id_callback() == _winpr_openssl_id)
 	{
@@ -255,7 +255,7 @@ static BOOL CALLBACK _winpr_openssl_initialize(PINIT_O
 	}
 #endif
 	/* SSL_load_error_strings() is void */
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
 	SSL_load_error_strings();
 	/* SSL_library_init() always returns "1" */
 	SSL_library_init();
@@ -296,7 +296,7 @@ BOOL winpr_CleanupSSL(DWORD flags)
 #ifdef WINPR_OPENSSL_LOCKING_REQUIRED
 		_winpr_openssl_cleanup_locking();
 #endif
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
 		CRYPTO_cleanup_all_ex_data();
 		ERR_free_strings();
 		EVP_cleanup();
@@ -307,7 +307,7 @@ BOOL winpr_CleanupSSL(DWORD flags)
 #ifdef WINPR_OPENSSL_LOCKING_REQUIRED
 	if (flags & WINPR_SSL_CLEANUP_THREAD)
 	{
-#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L) || defined(LIBRESSL_VERSION_NUMBER)
 		ERR_remove_state(0);
 #else
 		ERR_remove_thread_state(NULL);
