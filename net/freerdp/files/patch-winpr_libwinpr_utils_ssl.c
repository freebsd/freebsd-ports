--- winpr/libwinpr/utils/ssl.c.orig	2017-11-28 14:26:30 UTC
+++ winpr/libwinpr/utils/ssl.c
@@ -58,7 +58,7 @@ struct CRYPTO_dynlock_value
 };
 
 
-#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L) || defined(LIBRESSL_VERSION_NUMBER)
 static unsigned long _winpr_openssl_id(void)
 {
 	return (unsigned long)GetCurrentThreadId();
@@ -174,7 +174,7 @@ static BOOL _winpr_openssl_initialize_lo
 	}
 
 	/* Use the deprecated CRYPTO_get_id_callback() if building against OpenSSL < 1.0.0 */
-#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L) || defined(LIBRESSL_VERSION_NUMBER)
 
 	if (CRYPTO_get_id_callback())
 	{
@@ -224,7 +224,7 @@ static BOOL _winpr_openssl_cleanup_locki
 		CRYPTO_set_dynlock_destroy_callback(NULL);
 	}
 
-#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L) || defined(LIBRESSL_VERSION_NUMBER)
 
 	if (CRYPTO_get_id_callback() == _winpr_openssl_id)
 	{
@@ -279,7 +279,7 @@ static BOOL CALLBACK _winpr_openssl_init
 
 	if (flags & WINPR_SSL_INIT_ENABLE_FIPS)
 	{
-#if (OPENSSL_VERSION_NUMBER < 0x10001000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10001000L) || defined(LIBRESSL_VERSION_NUMBER)
 		WLog_ERR(TAG, "Openssl fips mode ENable not available on openssl versions less than 1.0.1!");
 #else
 		WLog_DBG(TAG, "Ensuring openssl fips mode is ENabled");
@@ -348,7 +348,7 @@ BOOL winpr_CleanupSSL(DWORD flags)
 
 BOOL winpr_FIPSMode(void)
 {
-#if (OPENSSL_VERSION_NUMBER < 0x10001000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10001000L) || defined(LIBRESSL_VERSION_NUMBER)
 	return FALSE;
 #else
 	return (FIPS_mode() == 1);
