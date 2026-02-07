--- libedsio/edsio.c.orig	2001-09-24 08:48:52.000000000 +0200
+++ libedsio/edsio.c	2006-05-29 16:45:35.000000000 +0200
@@ -179,9 +179,9 @@
 		    }
 		}
 
-	      while (g_queue_get_size (queued) > 0)
+	      while (g_queue_get_length (queued) > 0)
 		{
-		  DelayedEvent* de = g_queue_pop (queued);
+		  DelayedEvent* de = g_queue_pop_head (queued);
 
 		  for (i = 0; i < all_event_watchers->len; i += 1)
 		    {
@@ -211,7 +211,7 @@
 	      de->def = def;
 	      de->msg = out->str;
 
-	      g_queue_push (queued, de);
+	      g_queue_push_tail (queued, de);
 
 	      g_ptr_array_add (free_strings, out);
 	    }
@@ -1481,130 +1481,3 @@
 
   g_free (source);
 }
-
-/* Missing glib stuff
- */
-
-GQueue *
-g_queue_new (void)
-{
-  GQueue *q = g_new (GQueue, 1);
-
-  q->list = q->list_end = NULL;
-  q->list_size = 0;
-
-  return q;
-}
-
-
-void
-g_queue_free (GQueue *q)
-{
-  if (q)
-    {
-      if (q->list)
-        g_list_free (q->list);
-      g_free (q);
-    }
-}
-
-
-guint
-g_queue_get_size (GQueue *q)
-{
-  return (q == NULL) ? 0 : q->list_size;
-}
-
-
-void
-g_queue_push_front (GQueue *q, gpointer data)
-{
-  if (q)
-    {
-      q->list = g_list_prepend (q->list, data);
-
-      if (q->list_end == NULL)
-        q->list_end = q->list;
-
-      q->list_size++;
-    }
-}
-
-
-void
-g_queue_push_back (GQueue *q, gpointer data)
-{
-  if (q)
-    {
-      q->list_end = g_list_append (q->list_end, data);
-
-      if (! q->list)
-        q->list = q->list_end;
-      else
-        q->list_end = q->list_end->next;
-
-      q->list_size++;
-    }
-}
-
-
-gpointer
-g_queue_pop_front (GQueue *q)
-{
-  gpointer data = NULL;
-
-  if ((q) && (q->list))
-    {
-      GList *node;
-
-      node = q->list;
-      data = node->data;
-
-      if (! node->next)
-        {
-          q->list = q->list_end = NULL;
-          q->list_size = 0;
-        }
-      else
-        {
-          q->list = node->next;
-          q->list->prev = NULL;
-          q->list_size--;
-        }
-
-      g_list_free_1 (node);
-    }
-
-  return data;
-}
-
-
-gpointer
-g_queue_pop_back (GQueue *q)
-{
-  gpointer data = NULL;
-
-  if ((q) && (q->list))
-    {
-      GList *node;
-
-      node = q->list_end;
-      data = node->data;
-
-      if (! node->prev)
-	{
-          q->list = q->list_end = NULL;
-          q->list_size = 0;
-        }
-      else
-	{
-          q->list_end = node->prev;
-          q->list_end->next = NULL;
-          q->list_size--;
-        }
-
-      g_list_free_1 (node);
-    }
-
-  return data;
-}
