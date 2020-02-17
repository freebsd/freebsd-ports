--- nnrpd/tls.c.orig	2017-09-12 18:17:21 UTC
+++ nnrpd/tls.c
@@ -495,7 +495,7 @@ tls_init_serverengine(int verifydepth, int askcert, in
       syslog(L_NOTICE, "starting TLS engine");
 
 /* New functions have been introduced in OpenSSL 1.1.0. */
-#if OPENSSL_VERSION_NUMBER < 0x010100000L
+#if OPENSSL_VERSION_NUMBER < 0x010100000L || defined(LIBRESSL_VERSION_NUMBER)
     SSL_load_error_strings();
     SSLeay_add_ssl_algorithms();
     CTX = SSL_CTX_new(SSLv23_server_method());
@@ -652,7 +652,7 @@ tls_init_serverengine(int verifydepth, int askcert, in
         }
     }
 
-#if OPENSSL_VERSION_NUMBER >= 0x01010100fL
+#if OPENSSL_VERSION_NUMBER >= 0x01010100fL && !defined(LIBRESSL_VERSION_NUMBER)
     /* New API added in OpenSSL 1.1.1 for TLSv1.3 cipher suites. */
     if (tls_ciphers13 != NULL) {
         if (SSL_CTX_set_ciphersuites(CTX, tls_ciphers13) == 0) {
