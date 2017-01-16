--- src/openssl/openssl11_wrapper.h.orig	2016-10-16 22:48:17.000000000 +0000
+++ src/openssl/openssl11_wrapper.h	2017-01-16 14:02:41.553210002 +0000
@@ -9,7 +9,7 @@
  * same syntax. This file won't be required once OpenSSL 1.1.0 is the minimum
  * suported version.
  */
-#if (OPENSSL_VERSION_NUMBER < 0x10100000)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER))
 
 #define EVP_PKEY_up_ref(pKey)  CRYPTO_add(&((pKey)->references), 1, CRYPTO_LOCK_EVP_PKEY)
 
