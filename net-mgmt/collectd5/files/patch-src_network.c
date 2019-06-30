--- src/network.c.orig	2019-06-13 09:13:42 UTC
+++ src/network.c
@@ -2013,6 +2013,13 @@ static int sockent_client_connect(socken
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
