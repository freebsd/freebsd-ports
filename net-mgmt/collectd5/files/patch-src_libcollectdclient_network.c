--- src/libcollectdclient/network.c.orig
+++ src/libcollectdclient/network.c
@@ -174,6 +174,13 @@
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
