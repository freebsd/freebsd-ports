--- src/nv_driver.c.orig	2008-08-26 15:46:19.000000000 -0500
+++ src/nv_driver.c	2009-02-28 20:24:36.000000000 -0600
@@ -77,11 +77,22 @@
 static Bool	NVSetModeVBE(ScrnInfoPtr pScrn, DisplayModePtr pMode);
 
 #if XSERVER_LIBPCIACCESS
-/* For now, just match any NVIDIA PCI device and sort through them in the probe
- * routine */
+/* For now, just match any NVIDIA display device and sort through them in the
+ * probe routine */
+
+/*
+ * libpciaccess's masks are shifted by 8 bits compared to the ones in xf86Pci.h.
+ */
+#define LIBPCIACCESS_CLASS_SHIFT (PCI_CLASS_SHIFT - 8)
+#define LIBPCIACCESS_CLASS_MASK (PCI_CLASS_MASK >> 8)
+
 static const struct pci_id_match NVPciIdMatchList[] = {
-    { PCI_VENDOR_NVIDIA, PCI_MATCH_ANY, PCI_MATCH_ANY, PCI_MATCH_ANY, 0, 0, 0 },
-    { PCI_VENDOR_NVIDIA_SGS, PCI_MATCH_ANY, PCI_MATCH_ANY, PCI_MATCH_ANY, 0, 0, 0},
+    { PCI_VENDOR_NVIDIA, PCI_MATCH_ANY, PCI_MATCH_ANY, PCI_MATCH_ANY,
+      PCI_CLASS_DISPLAY << LIBPCIACCESS_CLASS_SHIFT, LIBPCIACCESS_CLASS_MASK, 0 },
+
+    { PCI_VENDOR_NVIDIA_SGS, PCI_MATCH_ANY, PCI_MATCH_ANY, PCI_MATCH_ANY,
+      PCI_CLASS_DISPLAY << LIBPCIACCESS_CLASS_SHIFT, LIBPCIACCESS_CLASS_MASK, 0 },
+
     { 0, 0, 0 }
 };
 #endif
