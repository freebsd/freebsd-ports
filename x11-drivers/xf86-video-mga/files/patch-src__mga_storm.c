--- ./src/mga_storm.c.orig	2009-07-26 20:37:46.000000000 -0700
+++ ./src/mga_storm.c	2010-03-09 17:58:54.168419688 -0800
@@ -1130,6 +1130,7 @@
     case PCI_CHIP_MGAG200_SE_B_PCI:
     case PCI_CHIP_MGAG200_WINBOND_PCI:
     case PCI_CHIP_MGAG200_EV_PCI:
+    case PCI_CHIP_MGAG200_EH_PCI:
 	pMga->SrcOrg = 0;
 	OUTREG(MGAREG_SRCORG, pMga->realSrcOrg);
 	OUTREG(MGAREG_DSTORG, pMga->DstOrg);
