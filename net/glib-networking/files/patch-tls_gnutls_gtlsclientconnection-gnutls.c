--- tls/gnutls/gtlsclientconnection-gnutls.c.orig	2012-03-04 18:47:23.000000000 -0500
+++ tls/gnutls/gtlsclientconnection-gnutls.c	2012-03-04 18:50:26.000000000 -0500
@@ -349,7 +349,8 @@ g_tls_client_connection_gnutls_finish_ha
 {
   GTlsClientConnectionGnutls *gnutls = G_TLS_CLIENT_CONNECTION_GNUTLS (conn);
 
-  if (g_error_matches (*inout_error, G_TLS_ERROR, G_TLS_ERROR_NOT_TLS) &&
+  if (inout_error &&
+      g_error_matches (*inout_error, G_TLS_ERROR, G_TLS_ERROR_NOT_TLS) &&
       gnutls->priv->cert_requested)
     {
       g_clear_error (inout_error);
@@ -361,7 +362,7 @@ g_tls_client_connection_gnutls_finish_ha
     {
       gnutls_datum session_data;
 
-      if (!*inout_error &&
+      if (inout_error && !*inout_error &&
 	  gnutls_session_get_data2 (g_tls_connection_gnutls_get_session (conn),
 				    &session_data) == 0)
 	{
