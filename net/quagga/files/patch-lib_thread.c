--- lib/thread.c.orig	2022-01-15 00:23:57.600963000 +0700
+++ lib/thread.c	2022-01-15 00:26:01.645088000 +0700
@@ -603,8 +603,12 @@ thread_add_fd (struct thread **thread_array, struct th
 static void
 thread_add_unuse (struct thread *thread)
 {
+  assert (thread);
+  /* thread_execute uses dummy threads, allocated on its stack */
+  if (thread->master == NULL)
+    return;
+
   thread->type = THREAD_UNUSED;
-  assert (thread->master != NULL && thread != NULL);
   assert (thread->next == NULL);
   assert (thread->prev == NULL);
   thread_list_add (&thread->master->unuse, thread);
@@ -1342,9 +1346,7 @@ thread_call (struct thread *thread)
     }
 #endif /* CONSUMED_TIME_CHECK */
 
-  
-  if (thread->master)
-    thread_add_unuse (thread);
+  thread_add_unuse (thread);
 }
 
 /* Execute thread */
