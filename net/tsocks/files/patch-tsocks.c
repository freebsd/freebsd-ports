--- tsocks.c.orig	2002-07-15 22:50:52 UTC
+++ tsocks.c
@@ -852,7 +852,7 @@ static int connect_server(struct connreq
                     sizeof(conn->serveraddr));
 
    show_msg(MSGDEBUG, "Connect returned %d, errno is %d\n", rc, errno); 
-	if (rc) {
+	if (rc && errno != EISCONN) {
       if (errno != EINPROGRESS) {
          show_msg(MSGERR, "Error %d attempting to connect to SOCKS "
                   "server (%s)\n", errno, strerror(errno));
@@ -862,6 +862,7 @@ static int connect_server(struct connreq
          conn->state = CONNECTING;
       }
    } else {
+      rc = 0;
       show_msg(MSGDEBUG, "Socket %d connected to SOCKS server\n", conn->sockid);
       conn->state = CONNECTED;
    }
