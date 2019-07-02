--- src/lib/crypto/OSSLCryptoFactory.cpp.orig	2019-07-02 17:52:44 UTC
+++ src/lib/crypto/OSSLCryptoFactory.cpp
@@ -141,8 +141,10 @@ OSSLCryptoFactory::OSSLCryptoFactory()
 	// Initialise OpenSSL
 	OpenSSL_add_all_algorithms();
 
+#if !( OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER) )
 	// Make sure RDRAND is loaded first
 	ENGINE_load_rdrand();
+#endif
 	// Locate the engine
 	rdrand_engine = ENGINE_by_id("rdrand");
 	// Use RDRAND if available
