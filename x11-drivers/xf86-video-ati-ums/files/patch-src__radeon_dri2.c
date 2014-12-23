--- src/radeon_dri2.c.orig	2012-06-25 08:19:41 UTC
+++ src/radeon_dri2.c
@@ -590,7 +590,7 @@ static void
 radeon_dri2_client_state_changed(CallbackListPtr *ClientStateCallback, pointer data, pointer calldata)
 {
     DRI2ClientEventsPtr pClientEventsPriv;
-    DRI2FrameEventPtr ref;
+    DRI2FrameEventPtr ref = NULL;
     NewClientInfoRec *clientinfo = calldata;
     ClientPtr pClient = clientinfo->client;
     pClientEventsPriv = GetDRI2ClientEvents(pClient);
