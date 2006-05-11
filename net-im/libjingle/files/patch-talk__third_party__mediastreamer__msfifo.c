--- ./talk/third_party/mediastreamer/msfifo.c.orig	Thu Mar 16 18:43:06 2006
+++ ./talk/third_party/mediastreamer/msfifo.c	Thu May 11 00:03:06 2006
@@ -54,7 +54,6 @@
 	MSBuffer *buf;
 	gint saved_offset=MAX(r_gran+r_offset,w_offset);
 	gint fifo_size;
-	gint tmp;
 	if (min_fifo_size==0) min_fifo_size=w_gran;
 	
 	/* we must allocate a fifo with a size multiple of min_fifo_size,
@@ -90,7 +89,7 @@
 	if (bsize>fifo->readsize)
 	{
 		ms_trace("Not enough data: bsize=%i, readsize=%i",bsize,fifo->readsize);
-		return (-ENODATA);
+		return -1;
 	}
 	
 	rnext=fifo->rd_ptr+bsize;
@@ -123,7 +122,7 @@
 	/* fix readsize and writesize */
 	fifo->readsize-=unwritten;
 	fifo->writesize+=unwritten;
-	fifo->wr_ptr+=written;
+        fifo->wr_ptr=fifo->prev_wr_ptr+written;
 }
 
 gint ms_fifo_get_write_ptr(MSFifo *fifo, gint bsize, void **ret_ptr)
@@ -137,7 +136,7 @@
 	{
 		ms_trace("Not enough space: bsize=%i, writesize=%i",bsize,fifo->writesize);
 		*ret_ptr=NULL;
-		return(-ENODATA);
+		return -1;
 	}
 	wnext=fifo->wr_ptr+bsize;
 	if (wnext<=fifo->w_end){
