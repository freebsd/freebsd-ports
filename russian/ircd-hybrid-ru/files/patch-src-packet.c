--- src/packet.c.orig	Mon Jun 21 09:43:24 2004
+++ src/packet.c	Mon Jun 21 09:44:15 2004
@@ -467,7 +467,7 @@
   parse_client_queued(client_p);
 
   /* Check to make sure we're not flooding */
-  if (IsPerson(client_p) &&
+  if (!(IsServer(client_p) || IsHandshake(client_p) || IsConnecting(client_p)) &&
       (dbuf_length(&client_p->localClient->buf_recvq) >
        (unsigned int)ConfigFileEntry.client_flood))
   {
