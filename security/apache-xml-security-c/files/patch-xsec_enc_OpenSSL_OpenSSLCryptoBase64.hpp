--- xsec/enc/OpenSSL/OpenSSLCryptoBase64.hpp.orig	2018-06-18 14:48:29.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoBase64.hpp	2018-11-02 18:30:38.642261000 +0000
@@ -205,7 +205,7 @@
     EVP_ENCODE_CTX *mp_ectx;              // Encode context
     EVP_ENCODE_CTX *mp_dctx;              // Decode context
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
     EVP_ENCODE_CTX m_ectx_store;
     EVP_ENCODE_CTX m_dctx_store;
 #endif 
