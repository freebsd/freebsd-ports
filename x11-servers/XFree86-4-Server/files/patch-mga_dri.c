Index: programs/Xserver/hw/xfree86/drivers/mga/mga_dri.c
===================================================================
RCS file: /cvsroot/dri/xc/xc/programs/Xserver/hw/xfree86/drivers/mga/mga_dri.c,v
retrieving revision 1.50
retrieving revision 1.51
diff -u -u -r1.50 -r1.51
--- programs/Xserver/hw/xfree86/drivers/mga/mga_dri.c	25 Mar 2003 11:20:38 -0000	1.50
+++ programs/Xserver/hw/xfree86/drivers/mga/mga_dri.c	5 Apr 2003 04:00:25 -0000	1.51
@@ -1359,6 +1359,7 @@
    if (pMga->irq) {
       drmCtlUninstHandler(pMga->drmFD);
       pMga->irq = 0;
+      pMga->reg_ien = 0;
    }
 
    /* Cleanup DMA */
