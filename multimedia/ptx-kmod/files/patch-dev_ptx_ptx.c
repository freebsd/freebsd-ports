--- dev/ptx/ptx.c.orig	2022-05-19 22:24:39 UTC
+++ dev/ptx/ptx.c
@@ -25,8 +25,6 @@ __FBSDID("$FreeBSD$");
 #include "ptx_sysctl.h"
 
 
-static devclass_t ptx_devclass;
-
 /*
  ***************************************
  * PCI Attachment structures and code
@@ -52,7 +50,13 @@ static driver_t ptx_driver = {
 	sizeof(struct ptx_softc),
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(ptx, pci, ptx_driver, 0, 0);
+#else
+static devclass_t ptx_devclass;
+
 DRIVER_MODULE(ptx, pci, ptx_driver, ptx_devclass, 0, 0);
+#endif
 MODULE_VERSION(ptx, 1);
 
 #define VENDOR_XILINX 0x10ee
