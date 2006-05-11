--- ./talk/third_party/mediastreamer/msbuffer.h.orig	Thu Mar 16 18:43:06 2006
+++ ./talk/third_party/mediastreamer/msbuffer.h	Thu May 11 00:12:20 2006
@@ -37,28 +37,28 @@
 {
     gchar *buffer;
     guint32 size;
-    guint16 ref_count;
-    guint16 flags;
-#define MS_BUFFER_CONTIGUOUS (1)
+    gint ref_count;
+    void (*freefn)(void *);
+    void *freearg;
 }MSBuffer;
 
 MSBuffer * ms_buffer_new(guint32 size);
+MSBuffer *ms_buffer_new_with_buf(char *extbuf, int size,void (*freefn)(void *), void *freearg);
 void ms_buffer_destroy(MSBuffer *buf);
 
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
 
-
-MSBuffer *ms_buffer_alloc(gint flags);
 MSMessage *ms_message_new(gint size);
 
 #define ms_message_set_buf(m,b) do { (b)->ref_count++; (m)->buffer=(b); (m)->data=(b)->buffer; (m)->size=(b)->size; }while(0)
