--- libfreerdp/crypto/crypto.c.orig	2017-08-05 09:35:32 UTC
+++ libfreerdp/crypto/crypto.c
@@ -388,7 +388,7 @@ BOOL x509_verify_certificate(CryptoCert cert, char* ce
 	if (cert_ctx == NULL)
 		goto end;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
 	OpenSSL_add_all_algorithms();
 #else
 	OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS \
