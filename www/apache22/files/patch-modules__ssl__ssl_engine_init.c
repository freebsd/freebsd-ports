--- modules/ssl/ssl_engine_init.c.orig	2014-07-16 06:04:38 UTC
+++ modules/ssl/ssl_engine_init.c
@@ -406,9 +406,11 @@ void ssl_init_Engine(server_rec *s, apr_
             ssl_die();
         }
 
+#ifdef ENGINE_CTRL_CHIL_SET_FORKCHECK
         if (strEQ(mc->szCryptoDevice, "chil")) {
             ENGINE_ctrl(e, ENGINE_CTRL_CHIL_SET_FORKCHECK, 1, 0, 0);
         }
+#endif
 
         if (!ENGINE_set_default(e, ENGINE_METHOD_ALL)) {
             ap_log_error(APLOG_MARK, APLOG_ERR, 0, s,
@@ -584,6 +586,10 @@ static void ssl_init_ctx_protocol(server
 #endif
 
 
+#ifdef SSL_NO_COMP
+#define OPENSSL_NO_COMP
+#endif
+
 #ifndef OPENSSL_NO_COMP
     if (sc->compression != TRUE) {
 #ifdef SSL_OP_NO_COMPRESSION
@@ -831,7 +837,11 @@ static void ssl_init_ctx_cert_chain(serv
         }
     }
 
-    n = SSL_CTX_use_certificate_chain(mctx->ssl_ctx,
+#ifndef HAVE_SSL_CTX_USE_CERTIFICATE_CHAIN
+          n = SSL_CTX_use_certificate_chain(mctx->ssl_ctx,
+#else
+          n = _SSL_CTX_use_certificate_chain(mctx->ssl_ctx,
+#endif
                                       (char *)chain,
                                       skip_first, NULL);
     if (n < 0) {
