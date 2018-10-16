--- src/socket.c.orig	2017-10-01 08:42:35 UTC
+++ src/socket.c
@@ -40,7 +40,7 @@
 # include <openssl/ssl.h>
 # include <openssl/err.h>
 # include <openssl/x509v3.h>
-# if OPENSSL_VERSION_NUMBER < 0x10100000L
+# if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #  define X509_OBJECT_get0_X509(o) ((o)->data.x509)
 #  define X509_STORE_get0_objects(o) ((o)->objs)
 # endif
@@ -270,6 +270,8 @@ socket_start_tls( conn_t *conn, void (*c
 
 	init_wakeup( &conn->ssl_fake, ssl_fake_cb, conn );
 	conn->ssl = SSL_new( ((server_conf_t *)conn->conf)->SSLContext );
+	if (ssl_return( "set server name", conn, SSL_set_tlsext_host_name( conn->ssl, conn->conf->host ) ) < 0)
+		return;
 	SSL_set_fd( conn->ssl, conn->fd );
 	SSL_set_mode( conn->ssl, SSL_MODE_ACCEPT_MOVING_WRITE_BUFFER );
 	socket_expect_read( conn, 1 );
