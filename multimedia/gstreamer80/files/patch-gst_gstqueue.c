--- gst/gstqueue.c.orig	Wed Feb  2 19:14:12 2005
+++ gst/gstqueue.c	Thu Mar 17 10:32:49 2005
@@ -474,6 +474,8 @@
 static void
 gst_queue_locked_flush (GstQueue * queue)
 {
+  GST_CAT_LOG_OBJECT (queue_dataflow, queue, "Flushing contents...");
+
   while (!g_queue_is_empty (queue->queue)) {
     GstData *data = g_queue_pop_head (queue->queue);
 
@@ -569,7 +571,9 @@
 
   if (GST_IS_BUFFER (data))
     GST_CAT_LOG_OBJECT (queue_dataflow, queue,
-        "adding buffer %p of size %d", data, GST_BUFFER_SIZE (data));
+        "adding buffer %p of size %d and time %" GST_TIME_FORMAT,
+        data, GST_BUFFER_SIZE (data),
+        GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (data)));
 
   /* We make space available if we're "full" according to whatever
    * the user defined as "full". Note that this only applies to buffers.
@@ -657,11 +661,11 @@
             GstScheduler *sched;
 
             GST_CAT_DEBUG_OBJECT (queue_dataflow, queue, "interrupted");
-            GST_QUEUE_MUTEX_UNLOCK;
             sched = gst_pad_get_scheduler (queue->sinkpad);
             if (!sched || gst_scheduler_interrupt (sched, GST_ELEMENT (queue))) {
-              goto out_unref;
+              goto ignore_interrupt;
             }
+            GST_QUEUE_MUTEX_UNLOCK;
             /* if we got here because we were unlocked after a
              * flush, we don't need to add the buffer to the
              * queue again */
@@ -693,6 +697,7 @@
             }
           }
 
+        ignore_interrupt:
           /* OK, we've got a serious issue here. Imagine the situation
            * where the puller (next element) is sending an event here,
            * so it cannot pull events from the queue, and we cannot
@@ -701,9 +706,16 @@
            * that, we handle pending upstream events here, too. */
           gst_queue_handle_pending_events (queue);
 
-          STATUS (queue, "waiting for item_del signal from thread using qlock");
-          g_cond_wait (queue->item_del, queue->qlock);
-          STATUS (queue, "received item_del signal from thread using qlock");
+          if (!queue->interrupt) {
+            STATUS (queue,
+                "waiting for item_del signal from thread using qlock");
+            g_cond_wait (queue->item_del, queue->qlock);
+            STATUS (queue, "received item_del signal from thread using qlock");
+          } else {
+            GST_CAT_DEBUG_OBJECT (queue_dataflow, queue,
+                "Not waiting, just adding buffer, after interrupt (bad!)");
+            break;
+          }
         }
 
         STATUS (queue, "post-full wait");
@@ -848,6 +860,9 @@
     queue->cur_level.bytes -= GST_BUFFER_SIZE (data);
     if (GST_BUFFER_DURATION (data) != GST_CLOCK_TIME_NONE)
       queue->cur_level.time -= GST_BUFFER_DURATION (data);
+    GST_CAT_LOG_OBJECT (queue_dataflow, queue,
+        "Got buffer of time %" GST_TIME_FORMAT,
+        GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (data)));
   }
 
   /* Now that we're done, we can lose our own reference to
@@ -947,6 +962,7 @@
         if (GST_EVENT_SEEK_FLAGS (event) & GST_SEEK_FLAG_FLUSH) {
           gst_queue_locked_flush (queue);
         }
+        break;
       default:
         break;
     }
@@ -974,10 +990,16 @@
     /* FIXME: this code assumes that there's no discont in the queue */
     switch (*fmt) {
       case GST_FORMAT_BYTES:
-        *value -= queue->cur_level.bytes;
+        if (*value >= queue->cur_level.bytes)
+          *value -= queue->cur_level.bytes;
+        else
+          *value = 0;
         break;
       case GST_FORMAT_TIME:
-        *value -= queue->cur_level.time;
+        if (*value >= queue->cur_level.time)
+          *value -= queue->cur_level.time;
+        else
+          *value = 0;
         break;
       default:
         /* FIXME */
