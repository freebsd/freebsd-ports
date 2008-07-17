--- ../../work_old/HandBrake/libhb/fifo.c	2008-02-19 19:28:17.000000000 +0100
+++ libhb/fifo.c	2008-06-17 23:02:48.000000000 +0200
@@ -6,7 +6,9 @@
 
 #include "hb.h"
 
-#ifndef SYS_DARWIN
+#if defined( SYS_FREEBSD )
+#include <stdlib.h>
+#elif !defined( SYS_DARWIN )
 #include <malloc.h>
 #endif
 
