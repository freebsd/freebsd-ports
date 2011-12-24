Index: src/connections.c
===================================================================
--- src/connections.c	(revision 2821)
+++ src/connections.c	(revision 2822)
@@ -1360,9 +1360,7 @@
 			}
 
 			con->renegotiations = 0;
-#ifndef OPENSSL_NO_TLSEXT
 			SSL_set_app_data(con->ssl, con);
-#endif
 			SSL_set_accept_state(con->ssl);
 			con->conf.is_ssl=1;
 
