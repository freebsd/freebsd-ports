Index: programs/Xserver/hw/xfree86/drivers/nv/nv_driver.c
===================================================================
RCS file: /home/ncvs/xfree/xc/programs/Xserver/hw/xfree86/drivers/nv/nv_driver.c,v
retrieving revision 1.103
retrieving revision 1.104
diff -u -u -r1.103 -r1.104
--- programs/Xserver/hw/xfree86/drivers/nv/nv_driver.c	18 Mar 2003 22:23:30 -0000	1.103
+++ programs/Xserver/hw/xfree86/drivers/nv/nv_driver.c	19 Mar 2003 18:02:49 -0000	1.104
@@ -181,6 +181,7 @@
  */
 
 static const char *vgahwSymbols[] = {
+    "vgaHWUnmapMem",
     "vgaHWDPMSSet",
     "vgaHWFreeHWRec",
     "vgaHWGetHWRec",
