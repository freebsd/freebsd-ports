Index: programs/Xserver/hw/xfree86/drivers/ati/radeon_dri.c
===================================================================
RCS file: /cvs/xc/programs/Xserver/hw/xfree86/drivers/ati/radeon_dri.c,v
retrieving revision 1.32
diff -p -u -r1.32 radeon_dri.c
--- programs/Xserver/hw/xfree86/drivers/ati/radeon_dri.c	2003/02/19 09:17:30	1.32
+++ programs/Xserver/hw/xfree86/drivers/ati/radeon_dri.c	2003/03/17 01:43:24
@@ -1585,6 +1585,7 @@ void RADEONDRICloseScreen(ScreenPtr pScr
     if (info->irq) {
 	drmCtlUninstHandler(info->drmFD);
 	info->irq = 0;
+	info->ModeReg.gen_int_cntl = 0;
     }
 
 				/* De-allocate vertex buffers */
