--- src/vesa.c.orig	2023-03-30 07:58:49 UTC
+++ src/vesa.c
@@ -464,10 +464,12 @@ VESAPciProbe(DriverPtr drv, int entity_num, struct pci
     if (pScrn != NULL) {
 	VESAPtr pVesa;
 
+#ifndef __FreeBSD__
 	if (pci_device_has_kernel_driver(dev)) {
 	    ErrorF("vesa: Ignoring device with a bound kernel driver\n");
 	    return FALSE;
 	}
+#endif
 
 	pVesa = VESAGetRec(pScrn);
 	VESAInitScrn(pScrn);
