--- src/network.c.orig	2020-03-08 15:57:09 UTC
+++ src/network.c
@@ -2045,6 +2045,13 @@ static int sockent_client_connect(sockent_t *se) /* {{
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
