--- programs/Xserver/hw/xfree86/os-support/bus/Pci.h.orig	Wed Sep 10 04:05:17 2003
+++ programs/Xserver/hw/xfree86/os-support/bus/Pci.h	Wed Sep 17 19:10:42 2003
@@ -255,6 +255,10 @@
 #  define ARCH_PCI_INIT linuxPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
 #  define INCLUDE_XF86_NO_DOMAIN
+# elif defined(FreeBSD)
+#  define ARCH_PCI_INIT freebsdPciInit
+#  define INCLUDE_XF86_MAP_PCI_MEM
+#  define INCLUDE_XF86_NO_DOMAIN
 # endif
 # define XF86SCANPCI_WRAPPER ia64ScanPCIWrapper
 #elif defined(__i386__)
@@ -315,14 +319,18 @@
 # elif defined(sun)
 #  define ARCH_PCI_INIT sparcPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
-# elif defined(__OpenBSD__) && defined(__sparc64__)
+# elif (defined(__OpenBSD__) || defined(__FreeBSD__)) && defined(__sparc64__)
 #  define  ARCH_PCI_INIT freebsdPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
 #  define INCLUDE_XF86_NO_DOMAIN
 # endif
 # define ARCH_PCI_PCI_BRIDGE sparcPciPciBridge
 #elif defined(__AMD64__)
-# define ARCH_PCI_INIT ix86PciInit
+# if defined(__FreeBSD__)
+#  define ARCH_PCI_INIT freebsdPciInit
+# else
+#  define ARCH_PCI_INIT ix86PciInit
+# endif
 # define INCLUDE_XF86_MAP_PCI_MEM
 # define INCLUDE_XF86_NO_DOMAIN
 # if defined(linux)
