--- programs/Xserver/hw/xfree86/os-support/bus/freebsdPci.c.orig	Thu May 15 18:53:48 2003
+++ programs/Xserver/hw/xfree86/os-support/bus/freebsdPci.c	Thu May 15 18:54:24 2003
@@ -84,7 +84,7 @@
 /* bridge      */	NULL
 };
 
-#if !defined(__OpenBSD__)
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #if X_BYTE_ORDER == X_BIG_ENDIAN
 #ifdef __sparc__
 #ifndef ASI_PL
