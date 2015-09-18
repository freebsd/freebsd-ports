$OpenBSD: patch-modules_ssl_ssl_engine_init_c,v 1.6 2015/09/07 06:32:04 jca Exp $

Don't attempt to use SSLv3_(client|server)_method, bail out if SSLv3 is
the only protocol requested.

--- modules/ssl/ssl_engine_init.c.orig	Sun Sep  6 15:23:52 2015
+++ modules/ssl/ssl_engine_init.c	Sun Sep  6 15:57:35 2015
@@ -484,9 +484,15 @@ static apr_status_t ssl_init_ctx_protocol(server_rec *
                  "Creating new SSL context (protocols: %s)", cp);
 
     if (protocol == SSL_PROTOCOL_SSLV3) {
+#ifndef OPENSSL_NO_SSL3
         method = mctx->pkp ?
             SSLv3_client_method() : /* proxy */
             SSLv3_server_method();  /* server */
+#else
+        ap_log_error(APLOG_MARK, APLOG_EMERG, 0, s,
+            "SSLv3 protocol not available");
+        return ssl_die(s);
+#endif
     }
     else if (protocol == SSL_PROTOCOL_TLSV1) {
         method = mctx->pkp ?
