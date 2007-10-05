--- lspci.c.orig	Fri Mar 30 11:56:35 2007
+++ lspci.c	Tue Oct  2 13:24:51 2007
@@ -58,8 +58,9 @@
  *  This increases our memory footprint, but only slightly since we don't
  *  use alloca() much.
  */
-
-#ifdef __GNUC__
+#if defined (__FreeBSD__) || defined (__NetBSD__) || defined (__OpenBSD__) || defined (__DragonFly__)
+/* alloca() is defined in stdlib.h */
+#elif defined(__GNUC__) && !defined(PCI_OS_WINDOWS)
 #include <alloca.h>
 #else
 #undef alloca
