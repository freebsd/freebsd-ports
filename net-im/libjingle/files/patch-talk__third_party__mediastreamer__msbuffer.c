--- ./talk/third_party/mediastreamer/msbuffer.c.orig	Wed May 10 23:56:49 2006
+++ ./talk/third_party/mediastreamer/msbuffer.c	Wed May 10 23:59:29 2006
@@ -34,31 +34,28 @@
 	/* allocate the data buffer: there is a lot of optmisation that can be done by using a pool of cached buffers*/
 	buf->buffer=((char*)(buf))+sizeof(MSBuffer); /* to avoid to do two allocations,
 					buffer info and buffer are contigous.*/
-	buf->flags=MS_BUFFER_CONTIGUOUS;
+	buf->freefn=NULL;
+	buf->freearg=NULL;
 	return(buf);
 }
 
-MSBuffer *ms_buffer_alloc(gint flags)
+MSBuffer *ms_buffer_new_with_buf(char *extbuf, int size,void (*freefn)(void *), void *freearg)
 {
 	MSBuffer *buf;
 	buf=(MSBuffer*)g_malloc(sizeof(MSBuffer));
 	buf->ref_count=0;
-	buf->size=0;
-	buf->buffer=NULL;
-	buf->flags=0;
+	buf->size=size;
+	buf->buffer=extbuf;
+	buf->freefn=freefn;
+	buf->freearg=freearg;
 	return(buf);
 }
 
 
 void ms_buffer_destroy(MSBuffer *buf)
 {
-	if (buf->flags & MS_BUFFER_CONTIGUOUS){
-		g_free(buf);
-	}
-	else {
-		g_free(buf->buffer);
+	if (buf->freefn!=NULL) buf->freefn(buf->freearg);
 		g_free(buf);
-	}
 }
 
 MSMessage *ms_message_alloc()
