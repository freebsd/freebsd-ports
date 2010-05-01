--- ./src/mga.h.orig	2009-07-27 17:24:51.000000000 -0700
+++ ./src/mga.h	2010-03-09 17:58:54.154420020 -0800
@@ -133,6 +133,10 @@
 #define PCI_CHIP_MGAG200_EV_PCI 0x0530
 #endif
 
+#ifndef PCI_CHIP_MGAG200_EH_PCI
+#define PCI_CHIP_MGAG200_EH_PCI 0x0533
+#endif
+
 /*
  * Read/write to the DAC via MMIO 
  */
@@ -474,6 +478,7 @@
     int is_G200SE:1;
     int is_G200WB:1;
     int is_G200EV:1;
+    int is_G200EH:1;
 
     int KVM;
 
