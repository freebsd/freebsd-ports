Index: programs/Xserver/hw/xfree86/drivers/nv/nv_setup.c
===================================================================
RCS file: /home/ncvs/xfree/xc/programs/Xserver/hw/xfree86/drivers/nv/nv_setup.c,v
retrieving revision 1.28
retrieving revision 1.29
diff -u -u -r1.28 -r1.29
--- programs/Xserver/hw/xfree86/drivers/nv/nv_setup.c	12 Mar 2003 21:27:18 -0000	1.28
+++ programs/Xserver/hw/xfree86/drivers/nv/nv_setup.c	4 Apr 2003 00:18:50 -0000	1.29
@@ -24,7 +24,7 @@
 /* Hacked together from mga driver and 3.3.4 NVIDIA driver by Jarno Paananen
    <jpaana@s2.org> */
 
-/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/nv/nv_setup.c,v 1.27 2003/02/10 23:42:51 mvojkovi Exp $ */
+/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/nv/nv_setup.c,v 1.28 2003/03/12 21:27:18 mvojkovi Exp $ */
 
 #include "nv_include.h"
 
@@ -424,6 +424,9 @@
         break;
     }
 
+    if(pNv->riva.Architecture == 3)
+       pNv->riva.PCRTC0 = pNv->riva.PGRAPH;
+
     if(pNv->SecondCRTC) {
        pNv->riva.PCIO = pNv->riva.PCIO0 + 0x2000;
        pNv->riva.PCRTC = pNv->riva.PCRTC0 + 0x800;
@@ -492,7 +495,6 @@
                                      frameBase+0x00C00000, 0x00008000);
             
     NVCommonSetup(pScrn);
-    pNv->riva.PCRTC = pNv->riva.PCRTC0 = pNv->riva.PGRAPH;
 }
 
 void
