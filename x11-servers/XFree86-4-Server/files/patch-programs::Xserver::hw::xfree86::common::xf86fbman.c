--- programs/Xserver/hw/xfree86/common/xf86fbman.c.orig	Sat Aug 28 13:14:32 2004
+++ programs/Xserver/hw/xfree86/common/xf86fbman.c	Sat Aug 28 13:16:03 2004
@@ -1115,12 +1115,10 @@
 
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
