--- src/radeon_dri2.c.orig	2013-02-22 19:31:34.000000000 +0000
+++ src/radeon_dri2.c	2013-02-22 19:31:47.000000000 +0000
@@ -578,7 +578,7 @@
 radeon_dri2_client_state_changed(CallbackListPtr *ClientStateCallback, pointer data, pointer calldata)
 {
     DRI2ClientEventsPtr pClientEventsPriv;
-    DRI2FrameEventPtr ref;
+    DRI2FrameEventPtr ref = NULL;
     NewClientInfoRec *clientinfo = calldata;
     ClientPtr pClient = clientinfo->client;
     pClientEventsPriv = GetDRI2ClientEvents(pClient);
