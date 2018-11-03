--- xsec/enc/OpenSSL/OpenSSLCryptoBase64.cpp.orig	2018-06-18 14:48:29.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoBase64.cpp	2018-11-02 18:30:38.642036000 +0000
@@ -48,7 +48,7 @@
 //           Construction/Destruction
 // --------------------------------------------------------------------------------
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
 OpenSSLCryptoBase64::OpenSSLCryptoBase64() : mp_ectx(&m_ectx_store), mp_dctx(&m_dctx_store) { }
 OpenSSLCryptoBase64::~OpenSSLCryptoBase64() { }
 #else
