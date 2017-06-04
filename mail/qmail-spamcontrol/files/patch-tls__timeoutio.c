--- tls_timeoutio.c.orig	2017-05-14 20:13:04.824311000 +0200
+++ tls_timeoutio.c	2017-05-14 20:15:42.360658000 +0200
@@ -75,10 +75,10 @@ int tls_timeoutrehandshake(int t, int rf
 
   SSL_renegotiate(ssl);
   r = tls_timeoutio(SSL_do_handshake, t, rfd, wfd, ssl, NULL, 0);
-  if (r <= 0 || ssl->type == SSL_ST_CONNECT) return r;
+  if (r <= 0 || SSL_get_state(ssl) == SSL_ST_CONNECT) return r;
 
   /* this is for the server only */
-  ssl->state = SSL_ST_ACCEPT;
+  SSL_set_connect_state(ssl);
   return tls_timeoutio(SSL_do_handshake, t, rfd, wfd, ssl, NULL, 0);
 }
 
