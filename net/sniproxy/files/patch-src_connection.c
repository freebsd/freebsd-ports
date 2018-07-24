--- src/connection.c.orig	2018-07-24 14:47:02 UTC
+++ src/connection.c
@@ -111,7 +111,7 @@ accept_connection(struct Listener *listener, struct ev
     int sockfd = accept4(listener->watcher.fd,
                     (struct sockaddr *)&con->client.addr,
                     &con->client.addr_len,
-                    O_NONBLOCK);
+                    SOCK_NONBLOCK);
 #else
     int sockfd = accept(listener->watcher.fd,
                     (struct sockaddr *)&con->client.addr,
