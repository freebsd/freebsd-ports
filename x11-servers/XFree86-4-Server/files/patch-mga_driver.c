--- programs/Xserver/hw/xfree86/drivers/mga/mga_driver.c.orig	Thu Sep 19 00:12:42 2002
+++ programs/Xserver/hw/xfree86/drivers/mga/mga_driver.c	Thu Sep 19 00:13:56 2002
@@ -2745,6 +2745,7 @@
 	    case PCI_CHIP_MGAG200:
 	    case PCI_CHIP_MGAG200_PCI:
 	    case PCI_CHIP_MGAG400:	      
+	    case PCI_CHIP_MGAG550:	      
 	      if(pMga->SecondCrtc == FALSE && pMga->HWCursor == TRUE) {
 		outMGAdac(MGA1064_CURSOR_BASE_ADR_LOW, 
 			  pMga->FbCursorOffset >> 10);
