--- src/srvc_im.c.orig	Fri Apr 29 23:38:46 2005
+++ src/srvc_im.c	Fri Apr 29 23:39:28 2005
@@ -272,7 +272,6 @@
 static int send_accept(struct mwConversation *c) {
   struct mwChannel *chan = c->channel;
   struct mwSession *s = mwChannel_getSession(chan);
-  struct mwUserStatus *stat = mwSession_getUserStatus(s);
   struct mwPutBuffer *b;
   struct mwOpaque *o;
 
@@ -284,8 +283,6 @@
   o = mwChannel_getAddtlAccept(chan);
   mwOpaque_clear(o);
   mwPutBuffer_finalize(o, b);
-
-  mwUserStatus_put(b, stat);
 
   return mwChannel_accept(chan);
 }
