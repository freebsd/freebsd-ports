--- src/nv_driver.c.orig	2017-01-17 22:41:33 UTC
+++ src/nv_driver.c
@@ -911,6 +911,8 @@ NVPciProbe(DriverPtr drv, int entity, struct pci_devic
                       NVGetPCIXpressChip(dev) : dev->vendor_id << 16 | dev->device_id;
     const char *name = xf86TokenToString(NVKnownChipsets, id);
 
+#ifndef __FreeBSD__
+    /* FreeBSD always has vgapci driver attached.  */
     if (pci_device_has_kernel_driver(dev)) {
         xf86DrvMsg(0, X_ERROR,
                    NV_NAME ": The PCI device 0x%x (%s) at %2.2d@%2.2d:%2.2d:%1.1d has a kernel module claiming it.\n",
@@ -919,6 +921,7 @@ NVPciProbe(DriverPtr drv, int entity, struct pci_devic
                    NV_NAME ": This driver cannot operate until it has been unloaded.\n");
         return FALSE;
     }
+#endif
 
     if(dev->vendor_id == PCI_VENDOR_NVIDIA && !name &&
        !NVIsSupported(id) && !NVIsG80(id)) {
@@ -1543,7 +1546,11 @@ NVPreInit(ScrnInfoPtr pScrn, int flags)
 	xf86FreeInt10(pNv->pInt);
 	return FALSE;
     }
+#ifdef __powerpc__ /* XXX probably MI */
+    vgaHWSetMmioFuncs(VGAHWPTR(pScrn), pNv->IOAddress, 0);
+#else
     vgaHWSetStdFuncs(VGAHWPTR(pScrn));
+#endif
     
     /* We use a programmable clock */
     pScrn->progClock = TRUE;
