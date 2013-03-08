--- tls/gnutls/gtlsconnection-gnutls.c.orig	2012-12-09 01:05:02.000000000 +0000
+++ tls/gnutls/gtlsconnection-gnutls.c	2012-12-09 01:14:46.000000000 +0000
@@ -752,7 +752,7 @@
   if (error)
     {
       g_set_error (error, G_TLS_ERROR, G_TLS_ERROR_MISC,
-                   errmsg, gnutls_strerror (status));
+                   "%s, %s", errmsg, gnutls_strerror (status));
     }
   return status;
 }
