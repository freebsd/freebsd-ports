--- include/ssl_private.h.orig	2016-04-19 10:08:10 UTC
+++ include/ssl_private.h
@@ -49,6 +49,9 @@
 /* Avoid tripping over an engine build installed globally and detected
  * when the user points at an explicit non-engine flavor of OpenSSL
  */
+#ifdef LIBRESSL_VERSION_NUMBER
+#define OPENSSL_NO_ENGINE
+#endif
 #ifndef OPENSSL_NO_ENGINE
 #include <openssl/engine.h>
 #endif
@@ -204,7 +207,7 @@
 #endif /* !defined(OPENSSL_NO_TLSEXT) && defined(SSL_set_tlsext_host_name) */
 
 /* OpenSSL 1.0.2 compatibility */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100001L || defined(LIBRESSL_VERSION_NUMBER)
 #define OpenSSL_version                  SSLeay_version
 #define OpenSSL_version_num              SSLeay
 #define OPENSSL_VERSION                  SSLEAY_VERSION
@@ -231,6 +234,10 @@
 #define TLS_server_method                SSLv23_server_method
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
 
+#ifdef LIBRESSL_VERSION_NUMBER
+#define SSL_CTX_add0_chain_cert          SSL_CTX_add_extra_chain_cert
+#endif
+
 #define MAX_ALPN_NPN_PROTO_SIZE 65535
 #define SSL_SELECTOR_FAILURE_CHOOSE_MY_LAST_PROTOCOL            1
 
