--- tls/gnutls/gtlsclientconnection-gnutls.c.orig	2015-03-17 14:53:17.000000000 +0100
+++ tls/gnutls/gtlsclientconnection-gnutls.c	2015-03-17 16:02:39.897699000 +0100
@@ -309,7 +309,8 @@ g_tls_client_connection_gnutls_finish_ha
 
   g_assert (inout_error != NULL);
 
-  if (g_error_matches (*inout_error, G_TLS_ERROR, G_TLS_ERROR_NOT_TLS) &&
+  if (inout_error &&
+      g_error_matches (*inout_error, G_TLS_ERROR, G_TLS_ERROR_NOT_TLS) &&
       gnutls->priv->cert_requested)
     {
       g_clear_error (inout_error);
@@ -327,7 +328,7 @@ g_tls_client_connection_gnutls_finish_ha
 
   if (gnutls->priv->session_id)
     {
-      if (!*inout_error)
+      if (inout_error && !*inout_error)
 	{
           if (!gnutls_session_is_resumed (g_tls_connection_gnutls_get_session (conn)))
             {
