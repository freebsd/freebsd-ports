--- mptable.c.orig	2011-09-15 15:37:32.000000000 -0700
+++ mptable.c	2011-09-15 15:37:46.000000000 -0700
@@ -37,7 +37,9 @@
 #include "mptable.h"
 #include "x86info.h"
 
+#ifndef __FreeBSD__
 typedef unsigned long vm_offset_t;
+#endif
 
 /* EBDA is @ 40:0e in real-mode terms */
 #define EBDA_POINTER			0x040e		  /* location of EBDA pointer */
