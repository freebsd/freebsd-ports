--- winpr/tools/makecert/makecert.c.orig	2017-07-24 08:46:54 UTC
+++ winpr/tools/makecert/makecert.c
@@ -620,7 +620,7 @@ int makecert_context_output_certificate_file(MAKECERT_
 				printf("Using default export password \"password\"\n");
 			}
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
 			OpenSSL_add_all_algorithms();
 			OpenSSL_add_all_ciphers();
 			OpenSSL_add_all_digests();
@@ -1008,7 +1008,7 @@ int makecert_context_process(MAKECERT_CONTEXT* context
 		key_length = atoi(arg->Value);
 	}
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
 	context->rsa = RSA_generate_key(key_length, RSA_F4, NULL, NULL);
 #else
 	{
@@ -1043,7 +1043,7 @@ int makecert_context_process(MAKECERT_CONTEXT* context
 	{
 		ASN1_TIME* before;
 		ASN1_TIME* after;
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
 		before = X509_get_notBefore(context->x509);
 		after = X509_get_notAfter(context->x509);
 #else
@@ -1242,7 +1242,7 @@ void makecert_context_free(MAKECERT_CONTEXT* context)
 #ifdef WITH_OPENSSL
 		X509_free(context->x509);
 		EVP_PKEY_free(context->pkey);
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
 		CRYPTO_cleanup_all_ex_data();
 #endif
 #endif
