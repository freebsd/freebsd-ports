--- programs/Xserver/hw/xfree86/drivers/nv/nv_hw.c.orig	Sat Oct  8 20:13:06 2005
+++ programs/Xserver/hw/xfree86/drivers/nv/nv_hw.c	Sat Oct  8 20:14:53 2005
@@ -915,7 +915,7 @@
     RIVA_HW_STATE *state
 )
 {
-    int i;
+    int i, j;
 
     pNv->PMC[0x0140/4] = 0x00000000;
     pNv->PMC[0x0200/4] = 0xFFFF00FF;
@@ -1162,6 +1162,10 @@
               pNv->PGRAPH[0x008C/4] = 0x60de8051;
               pNv->PGRAPH[0x0090/4] = 0x00008000;
               pNv->PGRAPH[0x0610/4] = 0x00be3c5f;
+
+              j = pNv->REGS[0x1540/4] & 0xff;
+              for(i = 0; !(j & 1); j >>= 1, i++);
+              pNv->PGRAPH[0x5000/4] = i;
 
               if((pNv->Chipset & 0xfff0) == 0x0040) {
                  pNv->PGRAPH[0x09b0/4] = 0x83280fff;
