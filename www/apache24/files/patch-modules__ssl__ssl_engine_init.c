# libressl support
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=196139
# https://issues.apache.org/bugzilla/show_bug.cgi?id=57375

--- modules/ssl/ssl_engine_init.c.orig	2015-01-15 12:20:33 UTC
+++ modules/ssl/ssl_engine_init.c
@@ -353,9 +353,11 @@ apr_status_t ssl_init_Engine(server_rec 
             return ssl_die(s);
         }
 
+#ifdef ENGINE_CTRL_CHIL_SET_FORKCHECK
         if (strEQ(mc->szCryptoDevice, "chil")) {
             ENGINE_ctrl(e, ENGINE_CTRL_CHIL_SET_FORKCHECK, 1, 0, 0);
         }
+#endif
 
         if (!ENGINE_set_default(e, ENGINE_METHOD_ALL)) {
             ap_log_error(APLOG_MARK, APLOG_EMERG, 0, s, APLOGNO(01889)
@@ -838,7 +840,11 @@ static apr_status_t ssl_init_ctx_cert_ch
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
