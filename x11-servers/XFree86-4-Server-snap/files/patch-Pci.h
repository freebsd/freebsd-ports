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
