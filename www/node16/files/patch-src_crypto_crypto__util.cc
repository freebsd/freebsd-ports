--- src/crypto/crypto_util.cc.orig	2023-06-12 06:44:17 UTC
+++ src/crypto/crypto_util.cc
@@ -194,10 +194,12 @@ void InitCryptoOnce() {
   // No-op with OPENSSL_NO_COMP builds of OpenSSL.
   sk_SSL_COMP_zero(SSL_COMP_get_compression_methods());
 
+#if OPENSSL_VERSION_MAJOR < 3
 #ifndef OPENSSL_NO_ENGINE
   ERR_load_ENGINE_strings();
   ENGINE_load_builtin_engines();
 #endif  // !OPENSSL_NO_ENGINE
+#endif  // OPENSSL_VERSION_MAJOR < 3
 
   NodeBIO::GetMethod();
 }
