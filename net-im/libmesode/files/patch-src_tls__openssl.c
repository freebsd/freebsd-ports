Patch from:

  https://github.com/profanity-im/libmesode/commit/532ed1e9d3e71e5bea0752e03dbacd4139d750d1

--- src/tls_openssl.c.orig	2019-10-11 19:08:58 UTC
+++ src/tls_openssl.c
@@ -320,6 +320,7 @@ tls_t *tls_new(xmpp_conn_t *conn)
         SSL_CTX_set_client_cert_cb(tls->ssl_ctx, NULL);
         SSL_CTX_set_mode(tls->ssl_ctx, SSL_MODE_ENABLE_PARTIAL_WRITE);
         SSL_CTX_set_verify(tls->ssl_ctx, SSL_VERIFY_PEER, verify_callback);
+        SSL_CTX_set_default_verify_paths(tls->ssl_ctx);
         if (conn->tls_cert_path) {
             SSL_CTX_load_verify_locations(tls->ssl_ctx, NULL, conn->tls_cert_path);
         }
