--- mptable.c.orig	Tue Oct  4 19:15:02 2005
+++ mptable.c	Tue Oct  4 19:15:09 2005
@@ -39,8 +39,6 @@
 #include "mptable.h"
 #include "x86info.h"
 
-typedef unsigned long vm_offset_t;
-
 /* EBDA is @ 40:0e in real-mode terms */
 #define EBDA_POINTER			0x040e		  /* location of EBDA pointer */
 
