--- openssl.c.orig	2018-03-27 13:10:48 UTC
+++ openssl.c
@@ -566,7 +566,7 @@ ZEND_GET_MODULE(openssl)
 #endif
 
 /* {{{ OpenSSL compatibility functions and macros */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined (LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || ( defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L )
 #define EVP_PKEY_get0_RSA(_pkey) _pkey->pkey.rsa
 #define EVP_PKEY_get0_DH(_pkey) _pkey->pkey.dh
 #define EVP_PKEY_get0_DSA(_pkey) _pkey->pkey.dsa
