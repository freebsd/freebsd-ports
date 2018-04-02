--- src/openssl/openssl_compat.h.orig	2017-09-12 13:21:09 UTC
+++ src/openssl/openssl_compat.h
@@ -16,6 +16,9 @@
  * OpenSSL 1.1.0 compatibility
  *
  *****************************************************************************/
+#if defined(XMLSEC_OPENSSL_API_110) && defined(LIBRESSL_VERSION_NUMBER) 
+#define EVP_CIPHER_CTX_encrypting(x)       ((x)->encrypt)
+#endif
 #if !defined(XMLSEC_OPENSSL_API_110)
 
 /* EVP_PKEY stuff */
