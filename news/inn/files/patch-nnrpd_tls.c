--- nnrpd/tls.c.orig	2017-09-12 18:17:21 UTC
+++ nnrpd/tls.c
@@ -499,7 +499,7 @@ tls_init_serverengine(int verifydepth, i
       Printf("starting TLS engine");
 
 /* New functions have been introduced in OpenSSL 1.1.0. */
-#if OPENSSL_VERSION_NUMBER < 0x010100000L
+#if OPENSSL_VERSION_NUMBER < 0x010100000L || defined(LIBRESSL_VERSION_NUMBER)
     SSL_load_error_strings();
     SSLeay_add_ssl_algorithms();
     CTX = SSL_CTX_new(SSLv23_server_method());
