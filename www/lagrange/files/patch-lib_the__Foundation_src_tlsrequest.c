--- lib/the_Foundation/src/tlsrequest.c.orig	2023-08-07 17:23:22 UTC
+++ lib/the_Foundation/src/tlsrequest.c
@@ -249,7 +249,9 @@ void init_Context(iContext *d) {
     SSL_load_error_strings();
     ERR_load_crypto_strings();
 #endif
+#if OPENSSL_VERSION_NUMBER < 0x30000000L
     ERR_load_BIO_strings();
+#endif
     d->ctx = SSL_CTX_new(TLS_client_method());
     if (!d->ctx) {
         iDebug("[TlsRequest] failed to initialize OpenSSL\n");
