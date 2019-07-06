--- lib/thread.c.orig	2018-02-19 21:24:55 UTC
+++ lib/thread.c
@@ -603,6 +603,8 @@ thread_add_fd (struct thread **thread_ar
 static void
 thread_add_unuse (struct thread *thread)
 {
+  if (thread->type == THREAD_UNUSED)
+	return;
   thread->type = THREAD_UNUSED;
   assert (thread->master != NULL && thread != NULL);
   assert (thread->next == NULL);
