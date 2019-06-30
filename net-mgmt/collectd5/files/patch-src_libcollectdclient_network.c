--- src/libcollectdclient/network.c.orig	2019-06-13 09:13:42 UTC
+++ src/libcollectdclient/network.c
@@ -178,6 +178,13 @@ static int server_open_socket(lcc_server
       continue;
     }
 
+    status = sendto(srv->fd, "", 1, 0, ai_ptr->ai_addr, ai_ptr->ai_addrlen);
+    if (status != 1) {
+      close(srv->fd);
+      srv->fd = -1;
+      continue;
+    }
+
     srv->sa = malloc(ai_ptr->ai_addrlen);
     if (srv->sa == NULL) {
       close(srv->fd);
