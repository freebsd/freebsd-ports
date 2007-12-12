--- vidix/pci.c.orig	2007-10-07 15:49:27.000000000 -0400
+++ vidix/pci.c	2007-11-14 03:12:26.000000000 -0500
@@ -484,8 +484,6 @@
 #include "sysdep/pci_arm32.c"
 #elif defined(__powerpc__)
 #include "sysdep/pci_powerpc.c"
-#elif defined(__x86_64__)
-/* Nothing here right now */
 #else
 #include "sysdep/pci_x86.c"
 #endif
