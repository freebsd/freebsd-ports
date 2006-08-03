--- datatype/h263/codec/video/vdecopcl.c	Thu Jul  8 21:56:22 2004
+++ datatype/h263/codec/video/vdecopcl.c	Fri Jul  8 01:58:47 2005
@@ -52,5 +52,5 @@
 //#include <stddef.h>
 #include "machine.h"
-#ifdef FOR_MAC
+#if defined(FOR_MAC) || defined(__FreeBSD__) || defined(_FREEBSD)
 #include <stdlib.h>
 #else
