Index: programs/Xserver/hw/xfree86/drivers/ati/r128_dri.c
===================================================================
RCS file: /cvs/xorg/xc/programs/Xserver/hw/xfree86/drivers/ati/r128_dri.c,v
retrieving revision 1.4
retrieving revision 1.4.4.1
diff -u -u -r1.4 -r1.4.4.1
--- programs/Xserver/hw/xfree86/drivers/ati/r128_dri.c	10 Jul 2004 14:22:35 -0000	1.4
+++ programs/Xserver/hw/xfree86/drivers/ati/r128_dri.c	15 Dec 2004 08:53:01 -0000	1.4.4.1
@@ -1297,6 +1297,7 @@
     if (info->irq) {
 	drmCtlUninstHandler(info->drmFD);
 	info->irq = 0;
+	info->gen_int_cntl = 0;
     }
 
 				/* De-allocate vertex buffers */
