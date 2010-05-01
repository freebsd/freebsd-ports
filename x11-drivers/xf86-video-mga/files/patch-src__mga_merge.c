--- ./src/mga_merge.c.orig	2009-07-27 17:24:03.000000000 -0700
+++ ./src/mga_merge.c	2010-03-09 17:58:54.164420182 -0800
@@ -362,6 +362,7 @@
     case PCI_CHIP_MGAG200_SE_B_PCI:
     case PCI_CHIP_MGAG200_WINBOND_PCI:
     case PCI_CHIP_MGAG200_EV_PCI:
+    case PCI_CHIP_MGAG200_EH_PCI:
     case PCI_CHIP_MGAG400:
     case PCI_CHIP_MGAG550:
 	MGAGSetupFuncs(pScrn);
@@ -516,6 +517,7 @@
 	case PCI_CHIP_MGAG200_SE_B_PCI:
         case PCI_CHIP_MGAG200_WINBOND_PCI:
         case PCI_CHIP_MGAG200_EV_PCI:
+        case PCI_CHIP_MGAG200_EH_PCI:
 	case PCI_CHIP_MGAG400:
 	case PCI_CHIP_MGAG550:
 	   maxPitch = 4096;
