--- gst/gstthread.c.orig	Wed Jul 10 15:22:00 2002
+++ gst/gstthread.c	Wed Jul 10 15:22:52 2002
@@ -147,7 +147,7 @@
   thread->cond = g_cond_new ();
 
   thread->ppid = getpid ();
-  thread->thread_id = -1;
+  thread->thread_id = (pthread_t) -1;
 }
 
 static void
@@ -276,8 +276,8 @@
       if (pthread_attr_init (&thread->attr) != 0)
 	g_warning ("pthread_attr_init returned an error !");
       if (gst_scheduler_get_preferred_stack (GST_ELEMENT_SCHED (element), &thread->stack, &stacksize)) {
-        if (pthread_attr_setstack (&thread->attr, thread->stack, stacksize) != 0) {
-          g_warning ("pthread_attr_setstack failed");
+        if (pthread_attr_setstacksize (&thread->attr, stacksize) != 0) {
+          g_warning ("pthread_attr_setstacksize failed");
           return GST_STATE_FAILURE;
         }
 	GST_DEBUG (GST_CAT_THREAD, "pthread attr set stack at %p of size %ld", 
