--- src/crypto/tls_openssl.c.orig	2016-10-02 18:51:11 UTC
+++ src/crypto/tls_openssl.c
@@ -59,7 +59,7 @@ typedef int stack_index_t;
 #endif /* SSL_set_tlsext_status_type */
 
 #if (OPENSSL_VERSION_NUMBER < 0x10100000L || \
-     defined(LIBRESSL_VERSION_NUMBER)) &&    \
+     (defined(LIBRESSL_VERSION_NUMBER)) && LIBRESSL_VERSION_NUMBER < 0x20700000L) && \
     !defined(BORINGSSL_API_VERSION)
 /*
  * SSL_get_client_random() and SSL_get_server_random() were added in OpenSSL
