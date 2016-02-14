--- tls/gnutls/gtlsclientconnection-gnutls.c.orig	2015-04-30 17:57:54.000000000 +0200
+++ tls/gnutls/gtlsclientconnection-gnutls.c	2015-08-06 17:06:17.000000000 +0200
@@ -322,7 +322,8 @@
 
   g_assert (inout_error != NULL);
 
-  if (g_error_matches (*inout_error, G_TLS_ERROR, G_TLS_ERROR_NOT_TLS) &&
+  if (inout_error &&
+      g_error_matches (*inout_error, G_TLS_ERROR, G_TLS_ERROR_NOT_TLS) &&
       gnutls->priv->cert_requested)
     {
       g_clear_error (inout_error);
@@ -339,7 +340,7 @@
     }
 
   resumed = gnutls_session_is_resumed (g_tls_connection_gnutls_get_session (conn));
-  if (*inout_error || !resumed)
+  if (inout_error && *inout_error || !resumed)
     {
       /* Clear session data since the server did not accept what we provided. */
       gnutls->priv->session_data_override = FALSE;
@@ -348,7 +349,7 @@
         g_tls_backend_gnutls_remove_session (GNUTLS_CLIENT, gnutls->priv->session_id);
     }
 
-  if (!*inout_error && !resumed)
+  if (inout_error && !*inout_error && !resumed)
     {
       gnutls_datum_t session_datum;
 
