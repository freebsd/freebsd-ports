--- libfreerdp/crypto/tls.c.orig	2016-11-24 14:45:22 UTC
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
@@ -805,7 +805,7 @@ int tls_connect(rdpTls* tls, BIO* underl
 	return tls_do_handshake(tls, TRUE);
 }
 
-#ifndef OPENSSL_NO_TLSEXT
+#if !defined(OPENSSL_NO_TLSEXT) && !defined(LIBRESSL_VERSION_NUMBER)
 static void tls_openssl_tlsext_debug_callback(SSL* s, int client_server,
         int type, unsigned char* data, int len, void* arg)
 {
@@ -949,7 +949,7 @@ BOOL tls_accept(rdpTls* tls, BIO* underl
 		return FALSE;
 	}
 
-#ifndef OPENSSL_NO_TLSEXT
+#if !defined(OPENSSL_NO_TLSEXT) && !defined(LIBRESSL_VERSION_NUMBER)
 	/**
 	 * The Microsoft iOS clients eventually send a null or even double null
 	 * terminated hostname in the SNI TLS extension!
