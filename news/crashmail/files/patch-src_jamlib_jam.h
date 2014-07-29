--- src/jamlib/jam.h.orig	Mon Sep 18 02:22:08 2000
+++ src/jamlib/jam.h	Tue Jan 21 18:01:07 2003
@@ -32,13 +32,18 @@
 #ifndef __JAM_H__
 #define __JAM_H__
 
+#include <sys/types.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <ctype.h>
 
 #ifndef linux
+#if defined(__FreeBSD__)
+typedef u_long ulong;	 /* must be 32 bits wide */
+#else
 typedef unsigned short ushort;   /* must be 16 bits wide */
 typedef unsigned long  ulong;    /* must be 32 bits wide */
+#endif
 #endif
 
 typedef unsigned char  uchar;    /* must be  8 bits wide */
