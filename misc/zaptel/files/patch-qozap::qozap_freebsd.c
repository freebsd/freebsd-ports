
$FreeBSD$

--- qozap/qozap_freebsd.c
+++ qozap/qozap_freebsd.c
@@ -56,6 +56,8 @@
 	  "CologneChip HFC-4S evaluation board" },
 	{ PCI_VENDOR_ID_CCD, PCI_DEVICE_ID_CCD_M4, 0xb520, 4,
 	  "Junghanns.NET quadBRI card" },
+	{ PCI_VENDOR_ID_CCD, PCI_DEVICE_ID_CCD_M4, 0xb540, 4,
+	  "Swyx 4xS0 SX2 QuadBri" },
 	{ PCI_VENDOR_ID_CCD, PCI_DEVICE_ID_CCD_M, 0xb552, 8,
 	  "Junghanns.NET octoBRI card" },
 	{ 0, 0 }
