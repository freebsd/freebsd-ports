Index: programs/Xserver/hw/xfree86/drivers/cirrus/cir_driver.c
===================================================================
RCS file: /cvs/xc/programs/Xserver/hw/xfree86/drivers/cirrus/cir_driver.c,v
retrieving revision 1.69
retrieving revision 1.70
diff -u -r1.69 -r1.70
--- programs/Xserver/hw/xfree86/drivers/cirrus/cir_driver.c	18 Jun 2003 16:17:38 -0000	1.69
+++ programs/Xserver/hw/xfree86/drivers/cirrus/cir_driver.c	8 Jun 2004 01:28:56 -0000	1.70
@@ -11,7 +11,7 @@
  *	Guy DESBIEF
  */
 
-/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/cirrus/cir_driver.c,v 1.69 2003/06/18 16:17:38 eich Exp $ */
+/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/cirrus/cir_driver.c,v 1.70 2004/06/08 01:28:56 dawes Exp $ */
 
 /* All drivers should typically include these */
 #include "xf86.h"
@@ -86,6 +86,8 @@
 	{ PCI_CHIP_GD5464BD,	"CL-GD5464BD" },
 	{ PCI_CHIP_GD5465,		"CL-GD5465" },
 	{ PCI_CHIP_GD7548,              "CL-GD7548" },
+	{ PCI_CHIP_GD7555,              "CL-GD7555" },
+	{ PCI_CHIP_GD7556,              "CL-GD7556" },
 	{-1,					NULL }
 };
 
@@ -103,6 +105,8 @@
 	{ PCI_CHIP_GD5464BD,PCI_CHIP_GD5464BD,	RES_SHARED_VGA },
 	{ PCI_CHIP_GD5465,	PCI_CHIP_GD5465,	RES_SHARED_VGA },
 	{ PCI_CHIP_GD7548,	PCI_CHIP_GD7548,	RES_SHARED_VGA },
+	{ PCI_CHIP_GD7555,	PCI_CHIP_GD7555,	RES_SHARED_VGA },
+	{ PCI_CHIP_GD7556,	PCI_CHIP_GD7556,	RES_SHARED_VGA },
 	{ -1,				-1,					RES_UNDEFINED}
 };
 
