--- programs/Xserver/hw/xfree86/common/xf86fbman.c.orig	Wed Nov 26 23:48:58 2003
+++ programs/Xserver/hw/xfree86/common/xf86fbman.c	Wed Sep  1 21:15:58 2004
@@ -1095,12 +1095,10 @@
 
     *size = 0;
     
-    if (!offman->LinearAreas) return FALSE;
-
     pLink = offman->LinearAreas;
-    pLinkRet = pLink;
 
-    if (!pLink->area) {
+    if (pLink && !pLink->area) {
+	pLinkRet = pLink;
 	while (pLink) {
 	    if (pLink->free) {
 		if (pLink->linear.size > pLinkRet->linear.size)
