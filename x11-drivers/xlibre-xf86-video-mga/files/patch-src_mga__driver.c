--- src/mga_driver.c.orig	2024-08-01 13:23:52 UTC
+++ src/mga_driver.c
@@ -702,6 +702,8 @@ MGAPciProbe(DriverPtr drv, int entity_num, struct pci_
     ScrnInfoPtr pScrn = NULL;
     MGAPtr pMga;
 
+#ifndef __FreeBSD__
+    /* FreeBSD always has vgapci driver attached.  */
     if (pci_device_has_kernel_driver(dev)) {
 	/* If it's a G200 server chip, it's probably on KMS, so bail; if not,
 	 * it might be using matroxfb, which is ok. */
@@ -721,6 +723,7 @@ MGAPciProbe(DriverPtr drv, int entity_num, struct pci_
 	        return FALSE;
 	}
     }
+#endif
 
     /* Allocate a ScrnInfoRec and claim the slot */
     pScrn = xf86ConfigPciEntity(pScrn, 0, entity_num, MGAPciChipsets,
