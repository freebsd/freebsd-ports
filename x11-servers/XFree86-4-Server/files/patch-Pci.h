--- programs/Xserver/hw/xfree86/os-support/bus/Pci.h.orig	Tue Mar  4 16:42:16 2003
+++ programs/Xserver/hw/xfree86/os-support/bus/Pci.h	Tue Mar  4 16:42:21 2003
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
@@ -298,7 +302,11 @@
 # endif
 # define ARCH_PCI_PCI_BRIDGE sparcPciPciBridge
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
