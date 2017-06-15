--- modules/ssl/ssl_engine_init.c.orig	2017-01-05 18:57:49 UTC
+++ modules/ssl/ssl_engine_init.c
@@ -251,9 +251,11 @@ void ssl_init_Engine(server_rec *s, apr_
             ssl_die();
         }
 
+#ifdef ENGINE_CTRL_CHIL_SET_FORKCHECK
         if (strEQ(mc->szCryptoDevice, "chil")) {
             ENGINE_ctrl(e, ENGINE_CTRL_CHIL_SET_FORKCHECK, 1, 0, 0);
         }
+#endif
 
         if (!ENGINE_set_default(e, ENGINE_METHOD_ALL)) {
             ap_log_error(APLOG_MARK, APLOG_ERR, 0, s,
@@ -446,6 +448,9 @@ static void ssl_init_ctx_protocol(server
     }
 #endif
 
+#ifdef SSL_NO_COMP
+#define OPENSSL_NO_COMP
+#endif
 
 #ifndef OPENSSL_NO_COMP
     if (sc->compression != TRUE) {
@@ -708,7 +713,11 @@ static void ssl_init_ctx_cert_chain(serv
     }
 
     ERR_clear_error();
+#ifndef HAVE_SSL_CTX_USE_CERTIFICATE_CHAIN
     n = SSL_CTX_use_certificate_chain(mctx->ssl_ctx,
+#else
+    n = _SSL_CTX_use_certificate_chain(mctx->ssl_ctx,
+#endif
                                       (char *)chain,
                                       skip_first, NULL);
     if (n < 0) {
