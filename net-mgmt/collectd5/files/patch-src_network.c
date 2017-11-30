--- src/network.c.orig
+++ src/network.c
@@ -2000,6 +2000,13 @@
       continue;
     }
 
+    status = sendto(client->fd, "", 1, 0, ai_ptr->ai_addr, ai_ptr->ai_addrlen);
+    if (status != 1) {
+      close(client->fd);
+      client->fd = -1;
+      continue;
+    }
+
     client->addr = calloc(1, sizeof(*client->addr));
     if (client->addr == NULL) {
       ERROR("network plugin: calloc failed.");
