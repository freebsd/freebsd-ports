--- libdha/pci.c	Sun Oct 22 18:32:26 2006
+++ libdha/pci.c	Sat Jun  9 17:09:11 2007
@@ -493,5 +493,5 @@
 #elif defined(__powerpc__)
 #include "sysdep/pci_powerpc.c"
-#elif defined(__x86_64__)
+#elif defined(__x86_64__) || defined(__amd64__)
 /* Nothing here right now */
 #else
