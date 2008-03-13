--- src/vmmouse.c.orig	Wed Sep 26 08:11:47 2007
+++ src/vmmouse.c	Sun Jan 20 17:10:54 2008
@@ -964,8 +964,11 @@
    VMMOUSE_INPUT_DATA  vmmouseInput;
    int ps2Buttons = 0;
    int numPackets;
+   VMMousePrivPtr mPriv;
+   double factorX, factorY;
 
    pMse = pInfo->private;  
+   mPriv = pMse->mousePriv;
    while((numPackets = VMMouseClient_GetInput(&vmmouseInput))){
       if (numPackets == VMMOUSE_ERROR) {
          VMMouseClient_Disable();
@@ -990,6 +993,13 @@
       dy = vmmouseInput.Y; 
       dz = (char)vmmouseInput.Z;
       dw = 0;
+
+      /* X server 1.4.0 does not call VMMouseConvertProc() so we scale coordinates here */
+      factorX = ((double) screenInfo.screens[mPriv->screenNum]->width) / (double) 65535;
+      factorY = ((double) screenInfo.screens[mPriv->screenNum]->height) / (double) 65535;
+      dx = dx * factorX + 0.5;
+      dy = dy * factorY + 0.5;
+
       /* post an event */
       pMse->PostEvent(pInfo, buttons, dx, dy, dz, dw);
    }
