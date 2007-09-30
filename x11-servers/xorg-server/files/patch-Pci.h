--- hw/xfree86/os-support/bus/Pci.h.orig	2007-09-06 02:48:26.000000000 +0200
+++ hw/xfree86/os-support/bus/Pci.h	2007-09-28 21:43:06.000000000 +0200
@@ -112,6 +112,10 @@
 #include "xf86Pci.h"
 #include "xf86PciInfo.h"
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#endif
+
 /*
  * Global Definitions
  */
@@ -123,6 +127,10 @@
 # define MAX_PCI_DOMAINS	512
 # define PCI_DOM_MASK	0x01fful
 # define MAX_PCI_BUSES	(MAX_PCI_DOMAINS*256) /* 256 per domain      */
+#elif defined(FreeBSD) && __FreeBSD_version >= 700053 && !defined(__i386__)
+# define MAX_PCI_DOMAINS	256 /* limited by 32-bit xf86 PCITAG */
+# define PCI_DOM_MASK	(MAX_PCI_DOMAINS - 1)
+# define MAX_PCI_BUSES	(MAX_PCI_DOMAINS*256) /* 256 per domain      */
 #else
 # define MAX_PCI_BUSES   256	/* Max number of PCI buses           */
 #endif
@@ -238,7 +246,9 @@
 # elif defined(__FreeBSD__) || defined(__OpenBSD__)
 #  define ARCH_PCI_INIT freebsdPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
-#  define INCLUDE_XF86_NO_DOMAIN
+#  if __FreeBSD_version < 700053 || defined(__OpenBSD__)
+#   define INCLUDE_XF86_NO_DOMAIN
+#  endif
 # elif defined(__NetBSD__)
 #  define ARCH_PCI_INIT netbsdPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
@@ -260,10 +270,12 @@
 # if defined(linux)
 #  define ARCH_PCI_INIT ia64linuxPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
-# elif defined(FreeBSD)
+# elif defined(FreeBSD) || defined(__OpenBSD__)
 #  define ARCH_PCI_INIT freebsdPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
-#  define INCLUDE_XF86_NO_DOMAIN
+#  if __FreeBSD_version < 700053 || defined(__OpenBSD__)
+#   define INCLUDE_XF86_NO_DOMAIN
+#  endif
 # endif
 # define XF86SCANPCI_WRAPPER ia64ScanPCIWrapper
 #elif defined(__i386__) || defined(i386)
@@ -293,7 +305,9 @@
 # elif defined(__FreeBSD__) || defined(__OpenBSD__)
 #  define  ARCH_PCI_INIT freebsdPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
-#  define INCLUDE_XF86_NO_DOMAIN
+#  if __FreeBSD_version < 700053 || defined(__OpenBSD__)
+#   define INCLUDE_XF86_NO_DOMAIN
+#  endif
 # elif defined(__NetBSD__)
 #  define ARCH_PCI_INIT netbsdPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
@@ -325,7 +339,9 @@
 # elif (defined(__OpenBSD__) || defined(__FreeBSD__)) && defined(__sparc64__)
 #  define  ARCH_PCI_INIT freebsdPciInit
 #  define INCLUDE_XF86_MAP_PCI_MEM
-#  define INCLUDE_XF86_NO_DOMAIN
+#  if __FreeBSD_version < 700053 || defined(__OpenBSD__)
+#   define INCLUDE_XF86_NO_DOMAIN
+#  endif
 # endif
 # if !defined(__FreeBSD__) && !defined(linux)
 #  define ARCH_PCI_PCI_BRIDGE sparcPciPciBridge
@@ -333,11 +349,14 @@
 #elif defined(__amd64__) || defined(__amd64)
 # if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #  define ARCH_PCI_INIT freebsdPciInit
+#  if __FreeBSD_version < 700053 || defined(__FreeBSD_kernel__)
+#   define INCLUDE_XF86_NO_DOMAIN
+#  endif
 # else
 #  define ARCH_PCI_INIT ix86PciInit
+#  define INCLUDE_XF86_NO_DOMAIN
 # endif
 # define INCLUDE_XF86_MAP_PCI_MEM
-# define INCLUDE_XF86_NO_DOMAIN
 # if defined(linux)
 #  define ARCH_PCI_OS_INIT linuxPciInit
 # endif
