--- datatype/h263/codec/video/vdecopcl.c.orig	Fri Oct 18 03:55:31 2002
+++ datatype/h263/codec/video/vdecopcl.c	Sat May 22 00:24:50 2004
@@ -37,7 +37,7 @@
 //#include <stdio.h>
 //#include <stddef.h>
 #include "machine.h"
-#ifdef FOR_MAC
+#if defined (FOR_MAC)  || defined (_FREEBSD)
 #include <stdlib.h>
 #else
 #include <malloc.h>
