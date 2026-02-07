--- libedsio/edsio.h.orig	2001-06-12 05:16:41.000000000 +0200
+++ libedsio/edsio.h	2006-05-29 16:45:35.000000000 +0200
@@ -480,49 +480,6 @@
 
 #endif
 
-/* Missing glib stuff
- */
-
-typedef struct _GQueue		GQueue;
-
-struct _GQueue
-{
-  GList *list;
-  GList *list_end;
-  guint list_size;
-};
-
-/* Queues
- */
-
-GQueue *	g_queue_new		(void);
-void		g_queue_free		(GQueue *q);
-guint		g_queue_get_size	(GQueue *q);
-void		g_queue_push_front	(GQueue *q, gpointer data);
-void		g_queue_push_back	(GQueue *q, gpointer data);
-gpointer	g_queue_pop_front	(GQueue *q);
-gpointer	g_queue_pop_back	(GQueue *q);
-
-#define g_queue_empty(queue) \
-	((((GQueue *)(queue)) && ((GQueue *)(queue))->list) ? FALSE : TRUE)
-
-#define g_queue_peek_front(queue) \
-	((((GQueue *)(queue)) && ((GQueue *)(queue))->list) ? \
-		((GQueue *)(queue))->list->data : NULL)
-
-#define g_queue_peek_back(queue) \
-	((((GQueue *)(queue)) && ((GQueue *)(queue))->list_end) ? \
-		((GQueue *)(queue))->list_end->data : NULL)
-
-#define g_queue_index(queue,ptr) \
-	((((GQueue *)(queue)) && ((GQueue *)(queue))->list) ? \
-		g_list_index (((GQueue *)(queue))->list, (ptr)) : -1)
-
-#define		g_queue_push		g_queue_push_back
-#define		g_queue_pop		g_queue_pop_front
-#define		g_queue_peek		g_queue_peek_front
-
-
 #ifdef __cplusplus
 }
 #endif
