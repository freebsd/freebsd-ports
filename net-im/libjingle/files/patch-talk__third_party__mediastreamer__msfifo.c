--- ./talk/third_party/mediastreamer/msfifo.c.orig	Thu Mar 16 18:43:06 2006
+++ ./talk/third_party/mediastreamer/msfifo.c	Fri Apr 21 10:56:34 2006
@@ -123,7 +123,7 @@
 	/* fix readsize and writesize */
 	fifo->readsize-=unwritten;
 	fifo->writesize+=unwritten;
-	fifo->wr_ptr+=written;
+        fifo->wr_ptr=fifo->prev_wr_ptr+written;
 }
 
 gint ms_fifo_get_write_ptr(MSFifo *fifo, gint bsize, void **ret_ptr)
