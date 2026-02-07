--- print-fddi.c.orig	1993-04-22 20:40:16 UTC
+++ print-fddi.c
@@ -54,6 +54,10 @@ static  char rcsid[] =
 #include "interface.h"
 #include "addrtoname.h"
 
+
+int     fddipad = 0;      /* for proper alignment of header */   
+
+
 /*
  * NOTE:  This is a very preliminary hack for FDDI support.
  * There are all sorts of wired in constants & nothing (yet)
