--- tls/openssl/gtlsclientconnection-openssl.c.orig	2026-09-10 21:18:59 UTC
+++ tls/openssl/gtlsclientconnection-openssl.c
@@ -372,6 +372,7 @@ set_max_protocol (GTlsClientConnectionOpenssl  *client
   return TRUE;
 }
 
+#ifdef SSL_CTX_set1_sigalgs_list
 static void
 set_signature_algorithm_list (GTlsClientConnectionOpenssl *client)
 {
@@ -383,6 +384,7 @@ set_signature_algorithm_list (GTlsClientConnectionOpen
 
   SSL_CTX_set1_sigalgs_list (client->ssl_ctx, signature_algorithm_list);
 }
+#endif
 
 static void
 set_curve_list (GTlsClientConnectionOpenssl *client)
@@ -491,7 +493,9 @@ g_tls_client_connection_openssl_initable_init (GInitab
 
   SSL_CTX_sess_set_new_cb (client->ssl_ctx, g_tls_client_connection_openssl_new_session);
 
+#ifdef SSL_CTX_set1_sigalgs_list
   set_signature_algorithm_list (client);
+#endif
   set_curve_list (client);
 
   ERR_clear_error ();
