--- xsec/enc/OpenSSL/OpenSSLSupport.cpp.orig	2018-06-18 14:48:29.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLSupport.cpp	2018-11-02 18:30:38.642471000 +0000
@@ -273,7 +273,7 @@
 
 #endif
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
 EvpEncodeCtxRAII::EvpEncodeCtxRAII() : mp_ctx(&mp_ctx_store) { };
 EvpEncodeCtxRAII::~EvpEncodeCtxRAII() { }
 #else
