--- src/via_vgahw.c.orig	2009-10-03 22:48:55.000000000 +0200
+++ src/via_vgahw.c	2012-02-08 10:43:08.000000000 +0100
@@ -36,6 +36,11 @@
 #include "via_driver.h" /* for HAVE_DEBUG */
 #include "via_vgahw.h"
 
+#if ABI_VIDEODRV_VERSION < 12
+#define PIOOFFSET hwp->PIOOffset
+#else
+#define PIOOFFSET 0
+#endif
 
 static CARD8
 ViaVgahwIn(vgaHWPtr hwp, int address)
@@ -43,7 +48,7 @@
     if (hwp->MMIOBase)
         return MMIO_IN8(hwp->MMIOBase, hwp->MMIOOffset + address);
     else
-        return inb(hwp->PIOOffset + address);
+        return inb(PIOOFFSET + address);
 }
 
 static void
@@ -52,7 +57,7 @@
     if (hwp->MMIOBase)
         MMIO_OUT8(hwp->MMIOBase, hwp->MMIOOffset + address, value);
     else
-        outb(hwp->PIOOffset + address, value);
+        outb(PIOOFFSET + address, value);
 }
 
 /*
