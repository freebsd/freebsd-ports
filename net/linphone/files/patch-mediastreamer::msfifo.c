
$FreeBSD$

--- mediastreamer/msfifo.c	2002/12/30 08:33:16	1.1
+++ mediastreamer/msfifo.c	2002/12/30 08:33:36
@@ -23,6 +23,9 @@
 #include "msutils.h"
 #include "msfifo.h"
 
+#ifndef ENODATA
+#define ENODATA  61
+#endif
 
 MSFifo * ms_fifo_new(MSBuffer *buf, gint r_gran, gint w_gran, gint r_offset, gint w_offset)
 {
