--- src/tls/tls_server.c.orig	2016-08-27 20:27:50 UTC
+++ src/tls/tls_server.c
@@ -174,7 +174,7 @@ static const char server_session_id_cont
 #endif					/* OPENSSL_VERSION_NUMBER */
 
  /* OpenSSL 1.1.0 bitrot */
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 typedef const unsigned char *session_id_t;
 
 #else
@@ -377,7 +377,7 @@ TLS_APPL_STATE *tls_server_init(const TL
      */
     tls_check_version();
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
     /*
      * Initialize the OpenSSL library by the book! To start with, we must
@@ -588,7 +588,7 @@ TLS_APPL_STATE *tls_server_init(const TL
     /*
      * 2015-12-05: Ephemeral RSA removed from OpenSSL 1.1.0-dev
      */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
     /*
      * According to OpenSSL documentation, a temporary RSA key is needed when
