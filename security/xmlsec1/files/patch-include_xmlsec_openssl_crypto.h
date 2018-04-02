--- include/xmlsec/openssl/crypto.h.orig	2017-09-12 13:21:09 UTC
+++ include/xmlsec/openssl/crypto.h
@@ -43,12 +43,12 @@ XMLSEC_CRYPTO_EXPORT const xmlChar*     xmlSecOpenSSLG
  * What version of the openssl API do we have? (also see configure.ac)
  *
  *******************************************************************/
-#if OPENSSL_VERSION_NUMBER == 0x20000000L && defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER == 0x20000000L && (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 /* Libressl decided to take over OpenSSL version 2.0.0, likely will create
  * issues down the road...
  */
 #define XMLSEC_OPENSSL_API_100      1
-#elif OPENSSL_VERSION_NUMBER >= 0x10100000L
+#elif (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x20700000L) || OPENSSL_VERSION_NUMBER >= 0x10100000L
 #define XMLSEC_OPENSSL_API_110      1
 #elif OPENSSL_VERSION_NUMBER >= 0x10000000L
 #define XMLSEC_OPENSSL_API_100      1
