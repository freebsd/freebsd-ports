Index: programs/Xserver/hw/xfree86/drivers/cirrus/alp_driver.c
===================================================================
RCS file: /cvs/xc/programs/Xserver/hw/xfree86/drivers/cirrus/alp_driver.c,v
retrieving revision 1.36
retrieving revision 1.37
diff -u -r1.36 -r1.37
--- programs/Xserver/hw/xfree86/drivers/cirrus/alp_driver.c	7 Nov 2003 22:49:58 -0000	1.36
+++ programs/Xserver/hw/xfree86/drivers/cirrus/alp_driver.c	8 Jun 2004 01:28:56 -0000	1.37
@@ -11,7 +11,7 @@
  *    Guy DESBIEF
  */
 
-/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/cirrus/alp_driver.c,v 1.36 2003/11/07 22:49:58 dawes Exp $ */
+/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/cirrus/alp_driver.c,v 1.37 2004/06/08 01:28:56 dawes Exp $ */
 
 /* All drivers should typically include these */
 #include "xf86.h"
@@ -109,6 +109,9 @@
 static void	AlpDisplayPowerManagementSet(ScrnInfoPtr pScrn,
 											int PowerManagementMode, int flags);
 
+static void PC98CIRRUS755xEnable(ScrnInfoPtr pScrn);
+static void PC98CIRRUS755xDisable(ScrnInfoPtr pScrn);
+
 /*
  * This is intentionally screen-independent.  It indicates the binding
  * choice made in the first PreInit.
@@ -143,6 +146,8 @@
 static int gd5446_MaxClocks[] = { 135100, 135100,  85500,  85500,      0 };
 static int gd5480_MaxClocks[] = { 135100, 200000, 200000, 135100, 135100 };
 static int gd7548_MaxClocks[] = {  80100,  80100,  80100,  80100,  80100 };
+static int gd7555_MaxClocks[] = {  80100,  80100,  80100,  80100,  80100 };
+static int gd7556_MaxClocks[] = {  80100,  80100,  80100,  80100,  80100 };
 
 /*
  * List of symbols from other modules that this module references.  This
@@ -453,6 +458,11 @@
 			break;
 	}
 	break;
+
+    case PCI_CHIP_GD7555:
+    case PCI_CHIP_GD7556:
+	videoram = 2048;   /*  for PC-9821 La13 etc.  */
+	break;
     }
 
     /* UNMap the Alp memory and MMIO areas */
@@ -567,7 +577,7 @@
 									pCir->PciInfo->device,
 									pCir->PciInfo->func);
 
-    if (xf86LoadSubModule(pScrn, "int10")) {
+    if (!xf86IsPc98() && xf86LoadSubModule(pScrn, "int10")) {
 	xf86LoaderReqSymLists(int10Symbols,NULL);
 	xf86DrvMsg(pScrn->scrnIndex,X_INFO,"initializing int10\n");
 	pInt = xf86InitInt10(pCir->pEnt->index);
@@ -653,6 +663,16 @@
 
 	from = X_DEFAULT;
 	pCir->HWCursor = FALSE;
+
+	switch (pCir->Chipset) {
+	case PCI_CHIP_GD7555:
+	case PCI_CHIP_GD7556:
+	  pCir->HWCursor = TRUE;
+	  break;
+	default:
+	  break;
+	}
+
 	if (xf86GetOptValBool(pCir->Options, OPTION_HW_CURSOR, &pCir->HWCursor))
 		from = X_CONFIG;
 
@@ -939,6 +959,12 @@
 		case PCI_CHIP_GD7548:
 		        p = gd7548_MaxClocks;
                         break;
+		case PCI_CHIP_GD7555:
+		        p = gd7555_MaxClocks;
+                        break;
+		case PCI_CHIP_GD7556:
+		        p = gd7556_MaxClocks;
+                        break;
 		}
 		if (!p)
 			return FALSE;
@@ -1425,6 +1451,9 @@
 
 	vgaHWProtect(pScrn, FALSE);
 
+	if (xf86IsPc98())
+		PC98CIRRUS755xEnable(pScrn);
+
 	return TRUE;
 }
 
@@ -1843,6 +1872,9 @@
 
 	AlpRestore(pScrn);
 	vgaHWLock(hwp);
+
+	if (xf86IsPc98())
+		PC98CIRRUS755xDisable(pScrn);
 }
 
 
@@ -1880,6 +1912,9 @@
 
 	pScrn->vtSema = FALSE;
 
+	if (xf86IsPc98())
+		PC98CIRRUS755xDisable(pScrn);
+
 	pScreen->CloseScreen = pCir->CloseScreen;
 	return (*pScreen->CloseScreen)(scrnIndex, pScreen);
 }
@@ -2142,3 +2177,52 @@
 		   box.y2 - pScrn->virtualY);
     }
 }
+
+static void
+PC98CIRRUS755xEnable(ScrnInfoPtr pScrn)  /*  enter_aile()  */
+{
+   unsigned int  index,data;
+   vgaHWPtr hwp = VGAHWPTR(pScrn);
+
+   outb(0xfac, 0x02);
+
+   outb(0x68, 0x0e);
+   outb(0x6a, 0x07);
+   outb(0x6a, 0x8f);
+   outb(0x6a, 0x06);
+
+   outw(VGA_SEQ_INDEX, 0x1206);         /*  unlock cirrus special  */
+
+   index = hwp->IOBase + VGA_CRTC_INDEX_OFFSET;
+   data  = hwp->IOBase + VGA_CRTC_DATA_OFFSET;
+   outb(index, 0x3c);
+   outb(data,  inb(data) & 0xef);
+   outb(index, 0x1a);
+   outb(data,  inb(data) & 0xf3);
+}
+
+static void
+PC98CIRRUS755xDisable(ScrnInfoPtr pScrn)  /*  leave_aile()  */
+{
+   unsigned int  index,data;
+   vgaHWPtr hwp = VGAHWPTR(pScrn);
+
+   outw(VGA_SEQ_INDEX, 0x1206);         /*  unlock cirrus special  */
+
+   index = hwp->IOBase + VGA_CRTC_INDEX_OFFSET;
+   data  = hwp->IOBase + VGA_CRTC_DATA_OFFSET;
+   outb(index, 0x3c);
+   outb(data,  0x71);
+   outb(index, 0x1a);
+   outb(data,  inb(data) | 0x0c);
+
+   outb(0xfac,0x00);
+
+   outb(0x68, 0x0f);
+   outb(0x6a, 0x07);
+   outb(0x6a, 0x8e);
+   outb(0x6a, 0x21);
+   outb(0x6a, 0x69);
+   outb(0x6a, 0x06);
+}
+
