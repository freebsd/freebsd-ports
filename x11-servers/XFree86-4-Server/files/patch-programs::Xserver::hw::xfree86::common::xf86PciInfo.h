Index: programs/Xserver/hw/xfree86/common/xf86PciInfo.h
===================================================================
RCS file: /cvs/xc/programs/Xserver/hw/xfree86/common/xf86PciInfo.h,v
retrieving revision 1.159
retrieving revision 1.160
diff -u -r1.159 -r1.160
--- programs/Xserver/hw/xfree86/common/xf86PciInfo.h	22 Mar 2004 17:01:14 -0000	1.159
+++ programs/Xserver/hw/xfree86/common/xf86PciInfo.h	8 Jun 2004 01:28:56 -0000	1.160
@@ -1,4 +1,4 @@
-/* $XFree86: xc/programs/Xserver/hw/xfree86/common/xf86PciInfo.h,v 1.159 2004/03/22 17:01:14 tsi Exp $ */
+/* $XFree86: xc/programs/Xserver/hw/xfree86/common/xf86PciInfo.h,v 1.160 2004/06/08 01:28:56 dawes Exp $ */
 
 /*
  * Copyright (c) 1995-2003 by The XFree86 Project, Inc.
@@ -317,6 +317,7 @@
 /* Cirrus Logic */
 #define PCI_CHIP_GD7548			0x0038
 #define PCI_CHIP_GD7555			0x0040
+#define PCI_CHIP_GD7556			0x004C
 #define PCI_CHIP_GD5430			0x00A0
 #define PCI_CHIP_GD5434_4		0x00A4
 #define PCI_CHIP_GD5434_8		0x00A8
