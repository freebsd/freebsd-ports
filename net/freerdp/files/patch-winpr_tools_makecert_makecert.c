--- winpr/tools/makecert/makecert.c.orig	2017-11-28 14:26:30 UTC
+++ winpr/tools/makecert/makecert.c
@@ -1275,7 +1275,7 @@ void makecert_context_free(MAKECERT_CONT
 #ifdef WITH_OPENSSL
 		X509_free(context->x509);
 		EVP_PKEY_free(context->pkey);
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
 		CRYPTO_cleanup_all_ex_data();
 #endif
 #endif
