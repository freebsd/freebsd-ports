--- src/rendition.h.orig	2015-10-11 22:31:54.085176000 +0200
+++ src/rendition.h	2015-10-11 22:32:12.657760000 +0200
@@ -14,9 +14,6 @@
 /* Everything using inb/outb, etc needs "compiler.h" */
 #include "compiler.h"
 
-/* Drivers for PCI hardware need this */
-#include "xf86PciInfo.h"
-
 /* Drivers that need to access the PCI config space directly need this */
 #include "xf86Pci.h"
 
@@ -28,9 +25,6 @@
 /* All drivers initialising the SW cursor need this */
 #include "mipointer.h"
 
-/* All drivers implementing backing store need this */
-#include "mibstore.h"
-
 /* All drivers using the mi colormap manipulation need this */
 #include "micmap.h"
 
@@ -69,4 +63,8 @@
 
 #include "compat-api.h"
 /* end of __RENDITION_H__ */
+
+#define PCI_CHIP_V1000 0x0001
+#define PCI_CHIP_V2x00 0x2000
+
 #endif
