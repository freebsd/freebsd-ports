Index: programs/Xserver/hw/xfree86/drivers/ati/atiprobe.c
===================================================================
RCS file: /cvs/xorg/xc/programs/Xserver/hw/xfree86/drivers/ati/atiprobe.c,v
retrieving revision 1.3
retrieving revision 1.3.2.2
diff -u -u -r1.3 -r1.3.2.2
--- programs/Xserver/hw/xfree86/drivers/ati/atiprobe.c	30 Jul 2004 20:30:51 -0000	1.3
+++ programs/Xserver/hw/xfree86/drivers/ati/atiprobe.c	15 Dec 2004 08:47:20 -0000	1.3.2.2
@@ -1554,6 +1560,9 @@
                     continue;
 
                 pPCI = pVideo->thisCard;
+		if (pPCI == NULL)
+		    continue;
+		
                 PciReg = pciReadLong(pPCI->tag, PCI_REG_USERCONFIG);
                 j = PciReg & 0x03U;
                 if (j == 0x03U)
