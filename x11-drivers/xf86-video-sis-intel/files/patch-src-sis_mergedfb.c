--- src/sis_mergedfb.c.orig	2008-06-06 00:39:10.000000000 +0400
+++ src/sis_mergedfb.c	2008-06-06 00:32:21.000000000 +0400
@@ -2631,13 +2631,13 @@
 
     REQUEST_SIZE_MATCH(xXineramaSelectInputReq);
 
-    pWin = SecurityLookupWindow(stuff->window, client, SecurityWriteAccess);
+    pWin = SecurityLookupWindow(stuff->window, client, DixWriteAccess);
     if(!pWin)
        return BadWindow;
 
     pHead = (SiSXineramaEventPtr *)SecurityLookupIDByType(client,
 						 pWin->drawable.id, EventType,
-						 SecurityWriteAccess);
+						 DixWriteAccess);
 
     if(stuff->enable & (XineramaLayoutChangeNotifyMask)) {
 
