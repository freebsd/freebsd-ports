--- HandBrake_old/libhb/fifo.c	2007-10-08 22:57:08.000000000 +0200
+++ libhb/fifo.c	2007-12-04 05:55:37.000000000 +0100
@@ -6,9 +6,7 @@
 
 #include "hb.h"
 
-#ifndef SYS_DARWIN
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 
 /* Fifo */
 struct hb_fifo_s
