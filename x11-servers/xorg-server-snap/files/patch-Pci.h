--- programs/Xserver/hw/xfree86/os-support/bus/Pci.h.orig	Thu Jan 20 06:51:21 2005
+++ programs/Xserver/hw/xfree86/os-support/bus/Pci.h	Thu Jan 20 06:52:09 2005
@@ -285,7 +285,7 @@
 #  define ARCH_PCI_INIT linuxPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
 #  define INCLUDE_XF86_NO_DOMAIN	/* Needs kernel work to remove */
-# elif defined(__OpenBSD__)
+# elif defined(__FreeBSD__) || defined(__OpenBSD__)
 #  define  ARCH_PCI_INIT freebsdPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
 #  define INCLUDE_XF86_NO_DOMAIN
