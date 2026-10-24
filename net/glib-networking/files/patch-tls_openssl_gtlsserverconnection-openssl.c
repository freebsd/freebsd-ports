--- tls/openssl/gtlsserverconnection-openssl.c.orig	2026-09-10 21:18:59 UTC
+++ tls/openssl/gtlsserverconnection-openssl.c
@@ -327,6 +327,7 @@ set_max_protocol (GTlsServerConnectionOpenssl  *server
   return TRUE;
 }
 
+#ifdef SSL_CTX_set1_sigalgs_list
 static void
 set_signature_algorithm_list (GTlsServerConnectionOpenssl *server)
 {
@@ -338,6 +339,7 @@ set_signature_algorithm_list (GTlsServerConnectionOpen
 
   SSL_CTX_set1_sigalgs_list (server->ssl_ctx, signature_algorithm_list);
 }
+#endif
 
 static void
 set_curve_list (GTlsServerConnectionOpenssl *server)
@@ -404,7 +406,9 @@ g_tls_server_connection_openssl_initable_init (GInitab
 
   SSL_CTX_add_session (server->ssl_ctx, server->session);
 
+#ifdef SSL_CTX_set1_sigalgs_list
   set_signature_algorithm_list (server);
+#endif
   set_curve_list (server);
 
   cert = g_tls_connection_get_certificate (G_TLS_CONNECTION (initable));
