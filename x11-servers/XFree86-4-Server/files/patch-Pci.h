--- programs/Xserver/hw/xfree86/os-support/bus/Pci.h.orig	Mon Dec 23 07:37:26 2002
+++ programs/Xserver/hw/xfree86/os-support/bus/Pci.h	Sat Jul 26 21:34:12 2003
@@ -230,6 +230,10 @@
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
@@ -291,14 +295,20 @@
 # elif defined(sun)
 #  define ARCH_PCI_INIT sparcPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
-# elif defined(__OpenBSD__) && defined(__sparc64__)
+# elif (defined(__OpenBSD__) || defined(__FreeBSD__)) && defined(__sparc64__)
 #  define  ARCH_PCI_INIT freebsdPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
 #  define INCLUDE_XF86_NO_DOMAIN
 # endif
+# if !defined(__FreeBSD__)
 # define ARCH_PCI_PCI_BRIDGE sparcPciPciBridge
+# endif
 #elif defined(__x86_64__)
-# define ARCH_PCI_INIT ix86PciInit
+# if defined(__FreeBSD__)
+#  define ARCH_PCI_INIT freebsdPciInit
+# else
+#  define ARCH_PCI_INIT ix86PciInit
+# endif
 # define INCLUDE_XF86_MAP_PCI_MEM
 # define INCLUDE_XF86_NO_DOMAIN
 # if defined(linux)
