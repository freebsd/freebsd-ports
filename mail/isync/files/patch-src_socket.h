--- src/socket.h.orig	2021-12-03 10:56:16 UTC
+++ src/socket.h
@@ -142,6 +142,7 @@ void socket_expect_activity( conn_t *sock, int expect 
 void socket_start_deflate( conn_t *conn );
 void socket_close( conn_t *sock );
 void socket_expect_activity( conn_t *sock, int expect );
+void socket_expect_eof( conn_t *sock );
 int socket_read( conn_t *sock, char *buf, uint len ); /* never waits */
 char *socket_read_line( conn_t *sock ); /* don't free return value; never waits */
 typedef enum { KeepOwn = 0, GiveOwn } ownership_t;
