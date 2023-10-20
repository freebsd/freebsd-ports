--- src/socket.c.orig	2021-12-03 10:56:16 UTC
+++ src/socket.c
@@ -810,6 +810,15 @@ socket_expect_activity( conn_t *conn, int expect )
 		conf_wakeup( &conn->fd_timeout, expect ? conn->conf->timeout : -1 );
 }
 
+void
+socket_expect_eof( conn_t *sock )
+{
+#ifdef SSL_OP_IGNORE_UNEXPECTED_EOF  // implies HAVE_LIBSSL
+	if (sock->ssl)
+		SSL_set_options( sock->ssl, SSL_OP_IGNORE_UNEXPECTED_EOF );
+#endif
+}
+
 int
 socket_read( conn_t *conn, char *buf, uint len )
 {
