--- vidix/pci.c.orig	2009-05-12 21:58:57.000000000 -0500
+++ vidix/pci.c	2009-07-23 20:42:47.861327948 -0500
@@ -481,8 +481,6 @@
 #include "sysdep/pci_arm32.c"
 #elif defined(__powerpc__)
 #include "sysdep/pci_powerpc.c"
-#elif defined(__x86_64__) || defined(__sh__)
-/* Nothing here right now */
 #else
 #include "sysdep/pci_x86.c"
 #endif
