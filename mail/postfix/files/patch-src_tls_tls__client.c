--- src/tls/tls_client.c.orig	2016-08-27 20:27:50 UTC
+++ src/tls/tls_client.c
@@ -299,7 +299,7 @@ TLS_APPL_STATE *tls_client_init(const TL
      */
     tls_check_version();
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
     /*
      * Initialize the OpenSSL library by the book! To start with, we must
