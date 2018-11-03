--- xsec/enc/OpenSSL/OpenSSLSupport.hpp.orig	2018-06-18 14:48:29.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLSupport.hpp	2018-11-02 18:30:38.642655000 +0000
@@ -88,7 +88,7 @@
 
 private:
     EVP_ENCODE_CTX *mp_ctx;
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
     EVP_ENCODE_CTX mp_ctx_store;
 #endif    
 };
