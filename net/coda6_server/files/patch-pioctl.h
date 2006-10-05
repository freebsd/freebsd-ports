--- coda-src/kerndep/pioctl.h.orig	Thu Oct  5 11:54:04 2006
+++ coda-src/kerndep/pioctl.h	Thu Oct  5 11:54:20 2006
@@ -81,7 +81,7 @@
 /* unpacking macros */
 #ifndef _IOC_NR
 
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 #define _IOC_TYPEMASK	0xff
 #define _IOC_TYPESHIFT	8
 #define _IOC_NRMASK	0xff
