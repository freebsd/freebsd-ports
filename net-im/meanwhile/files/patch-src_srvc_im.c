--- src/srvc_im.c.orig	Thu Jun 24 20:53:09 2004
+++ src/srvc_im.c	Thu Jun 24 20:53:33 2004
@@ -160,12 +160,14 @@
   struct mwSession *s;
   struct mwChannelSet *cs;
   unsigned int a, b;
+  char *buf;
+  gsize n;
   
   s = chan->session;
   cs = s->channels;
 
-  char *buf = msg->addtl.data;
-  gsize n = msg->addtl.len;
+  buf = msg->addtl.data;
+  n = msg->addtl.len;
 
   if( (msg->service != Service_IM) ||
       (msg->proto_type != Protocol_IM) ||
