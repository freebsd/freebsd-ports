--- coda-src/kerndep/pioctl.h.orig	Thu Aug 26 17:23:04 2004
+++ coda-src/kerndep/pioctl.h	Tue Nov 16 22:04:33 2004
@@ -104,7 +104,7 @@
 /* unpacking macros */
 #ifndef _IOC_NR
 
-#if defined(__CYGWIN32__) || defined(__NetBSD__)
+#if defined(__CYGWIN32__) || defined(__NetBSD__) || defined(__FreeBSD__)
 #define _IOC_TYPEMASK	0xff
 #define _IOC_TYPESHIFT	8
 #define _IOC_NRMASK	0xff
