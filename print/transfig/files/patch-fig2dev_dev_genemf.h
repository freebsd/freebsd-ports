--- fig2dev/dev/genemf.h.orig	Thu Dec 19 07:42:05 2002
+++ fig2dev/dev/genemf.h	Tue Jan  7 20:16:08 2003
@@ -30,8 +30,10 @@
 #ifndef __USE_MISC
 /* Old compatibility names for C types.  */
 typedef unsigned long int ulong;
+#ifndef __FreeBSD__
 typedef unsigned short int ushort;
 typedef unsigned int uint;
+#endif
 #endif
 
 
