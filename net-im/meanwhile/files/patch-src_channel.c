--- src/channel.c.orig	Mon Jun 21 12:14:14 2004
+++ src/channel.c	Sun Jul  4 03:26:25 2004
@@ -293,7 +293,7 @@
 
   if(chan->status == mwChannel_OPEN) {
 
-    g_message("sending %u bytes on channel 0x%08x", msg->data.len, chan->id);
+    g_message("sending %lu bytes on channel 0x%08x", (unsigned long)(msg->data.len), chan->id);
     ret = mwSession_send(chan->session, (struct mwMessage *) msg);
     mwMessage_free(MW_MESSAGE(msg));
 
