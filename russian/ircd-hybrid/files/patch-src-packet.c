--- src/packet.c.orig	Mon Nov 15 14:41:32 2004
+++ src/packet.c	Mon Nov 15 14:42:04 2004
@@ -531,7 +531,7 @@
   parse_client_queued(client_p);
 
   /* Check to make sure we're not flooding */
-  if (IsPerson(client_p) &&
+  if (!(IsServer(client_p) || IsHandshake(client_p) || IsConnecting(client_p)) &&
       (linebuf_alloclen(&client_p->localClient->buf_recvq) >
        ConfigFileEntry.client_flood))
   {
