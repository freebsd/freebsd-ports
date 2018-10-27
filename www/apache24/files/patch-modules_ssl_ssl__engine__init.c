--- modules/ssl/ssl_engine_init.c.orig	2018-02-13 23:43:36 UTC
+++ modules/ssl/ssl_engine_init.c
@@ -547,7 +547,7 @@ static apr_status_t ssl_init_ctx_protoco
     char *cp;
     int protocol = mctx->protocol;
     SSLSrvConfigRec *sc = mySrvConfig(s);
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
     int prot;
 #endif
 
@@ -1492,7 +1492,7 @@ static apr_status_t ssl_init_proxy_certs
     X509_STORE_CTX *sctx;
     X509_STORE *store = SSL_CTX_get_cert_store(mctx->ssl_ctx);
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL && !defined(LIBRESSL_VERSION_NUMBER)
     /* For OpenSSL >=1.1.1, turn on client cert support which is
      * otherwise turned off by default (by design).
      * https://github.com/openssl/openssl/issues/6933 */
