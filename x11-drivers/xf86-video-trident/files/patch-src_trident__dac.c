# Fix a style warning
#
--- src/trident_dac.c.orig	2013-02-07 07:56:43 UTC
+++ src/trident_dac.c
@@ -1226,8 +1226,8 @@ Tridentddc1Read(ScrnInfoPtr pScrn)
     OUTW(0x3C4, (temp << 8) | NewMode1);
 
     /* Wait until vertical retrace is in progress. */
-    while (INB(vgaIOBase + 0xA) & 0x08);
-    while (!(INB(vgaIOBase + 0xA) & 0x08));
+    while (INB(vgaIOBase + 0xA) & 0x08) {}
+    while (!(INB(vgaIOBase + 0xA) & 0x08)) {}
 
     /* Get the result */
     OUTB(vgaIOBase + 4, I2C);
