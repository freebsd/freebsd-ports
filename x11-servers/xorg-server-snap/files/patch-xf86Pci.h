Index: programs/Xserver/hw/xfree86/os-support/bus/xf86Pci.h
===================================================================
RCS file: /work/eich/freedesktop/cvs/xorg/xc/programs/Xserver/hw/xfree86/os-support/bus/xf86Pci.h,v
retrieving revision 1.1.1.2
diff -u -r1.1.1.2 xf86Pci.h
--- programs/Xserver/hw/xfree86/os-support/bus/xf86Pci.h	25 Nov 2003 19:28:50 -0000	1.1.1.2
+++ programs/Xserver/hw/xfree86/os-support/bus/xf86Pci.h	2 Mar 2005 16:08:29 -0000
@@ -329,7 +329,7 @@
 #define PCI_MAP_IS_MEM(b)	(!PCI_MAP_IS_IO(b))
 
 #define PCI_MAP_IS64BITMEM(b)	\
-	(((b) & PCI_MAP_MEMORY_TYPE_MASK) == PCI_MAP_MEMORY_TYPE_64BIT)
+	  (((b) & PCI_MAP_MEMORY_TYPE) == PCI_MAP_MEMORY_TYPE_64BIT)
 
 #define PCIGETMEMORY(b)		((b) & PCI_MAP_MEMORY_ADDRESS_MASK)
 #define PCIGETMEMORY64HIGH(b)	(*((CARD32*)&b + 1))
