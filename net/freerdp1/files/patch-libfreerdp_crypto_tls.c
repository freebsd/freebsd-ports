--- libfreerdp/crypto/tls.c.orig	2014-09-11 22:46:32 UTC
+++ libfreerdp/crypto/tls.c
@@ -218,9 +218,9 @@ static long bio_rdp_tls_ctrl(BIO* bio, i
 		case BIO_CTRL_RESET:
 			SSL_shutdown(tls->ssl);
 
-			if (tls->ssl->handshake_func == tls->ssl->method->ssl_connect)
+			if (SSL_in_connect_init(tls->ssl))
 				SSL_set_connect_state(tls->ssl);
-			else if (tls->ssl->handshake_func == tls->ssl->method->ssl_accept)
+			else if (SSL_in_accept_init(tls->ssl))
 				SSL_set_accept_state(tls->ssl);
 
 			SSL_clear(tls->ssl);
