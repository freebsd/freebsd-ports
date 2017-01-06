--- src/openssl/app.c.orig	2017-01-05 18:07:26.936917000 +0900
+++ src/openssl/app.c	2017-01-05 18:08:34.388575000 +0900
@@ -61,7 +61,7 @@
 int
 xmlSecOpenSSLAppInit(const char* config) {
     
-#if (OPENSSL_VERSION_NUMBER < 0x10100000)
+#if !defined(XMLSEC_OPENSSL_110)
     ERR_load_crypto_strings();
     OPENSSL_config(NULL);
     OpenSSL_add_all_algorithms();
@@ -119,7 +119,7 @@
 xmlSecOpenSSLAppShutdown(void) {
     xmlSecOpenSSLAppSaveRANDFile(NULL);
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000)
+#if !defined(XMLSEC_OPENSSL_110)
     RAND_cleanup();
     EVP_cleanup();
 
