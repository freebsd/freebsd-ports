--- src/ucs/async/thread.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucs/async/thread.c
@@ -224,14 +224,23 @@ out_unlock:
 err:
     --ucs_async_thread_global_context.use_count;
 out_unlock:
-    ucs_assert_always(ucs_async_thread_global_context.thread != NULL);
-    *thread_p = ucs_async_thread_global_context.thread;
+    if (status == UCS_OK) {
+        ucs_assert_always(ucs_async_thread_global_context.thread != NULL);
+        *thread_p = ucs_async_thread_global_context.thread;
+    } else {
+        *thread_p = NULL;
+    }
+
     pthread_mutex_unlock(&ucs_async_thread_global_context.lock);
     return status;
 }
 
 static int ucs_async_thread_is_from_async()
 {
+    if (ucs_async_thread_global_context.thread == NULL) {
+        return 0;
+    }
+
     return pthread_self() == ucs_async_thread_global_context.thread->thread_id;
 }
 
@@ -346,6 +355,10 @@ static ucs_status_t ucs_async_thread_remove_event_fd(u
     ucs_async_thread_t *thread = ucs_async_thread_global_context.thread;
     ucs_status_t status;
 
+    if (thread == NULL) {
+        return UCS_ERR_NO_ELEM;
+    }
+
     status = ucs_event_set_del(thread->event_set, event_fd);
     if (status != UCS_OK) {
         return status;
@@ -359,6 +372,9 @@ ucs_async_thread_modify_event_fd(ucs_async_context_t *
 ucs_async_thread_modify_event_fd(ucs_async_context_t *async, int event_fd,
                                  ucs_event_set_types_t events)
 {
+    if (ucs_async_thread_global_context.thread == NULL) {
+        return UCS_ERR_NO_ELEM;
+    }
     /* Store file descriptor into void * storage without memory allocation. */
     return ucs_event_set_mod(ucs_async_thread_global_context.thread->event_set,
                              event_fd, events, (void *)(uintptr_t)event_fd);
@@ -421,6 +437,11 @@ static ucs_status_t ucs_async_thread_remove_timer(ucs_
                                                   int timer_id)
 {
     ucs_async_thread_t *thread = ucs_async_thread_global_context.thread;
+
+    if (thread == NULL) {
+        return UCS_ERR_NO_ELEM;
+    }
+
     ucs_timerq_remove(&thread->timerq, timer_id);
     ucs_async_pipe_push(&thread->wakeup);
     ucs_async_thread_stop();
