--- ./talk/third_party/mediastreamer/msbuffer.h.orig	Thu Mar 16 18:43:06 2006
+++ ./talk/third_party/mediastreamer/msbuffer.h	Fri Apr 21 10:56:34 2006
@@ -48,11 +48,12 @@
 struct _MSMessage
 {
    MSBuffer *buffer; /* points to a MSBuffer */
-   void *data;          /*points to buffer->buffer  */
+   char *data;          /*points to buffer->buffer  */
    guint32 size;   /* the size of the buffer to read in data. It may not be the
    								physical size (I mean buffer->buffer->size */
    struct _MSMessage *next;
    struct _MSMessage *prev;  /* MSMessage are queued into MSQueues */
+   gboolean markbit;
 };
 
 typedef struct _MSMessage MSMessage;
