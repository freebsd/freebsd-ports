--- src/gskhook.c.orig	Sat Dec 11 07:30:36 2004
+++ src/gskhook.c	Sun Jan 30 23:53:21 2005
@@ -121,12 +121,12 @@
 static inline void
 gsk_hook_add_to_nonblocking_list (GskHook *hook)
 {
+  GskMainLoop *loop = gsk_main_loop_default ();
+  NBThreadData *data = main_loop_force_nonblocking_data (loop);
   { /* A Test TED*/
     GObject *object = GSK_HOOK_GET_OBJECT(hook);
     (void)object;
   }
-  GskMainLoop *loop = gsk_main_loop_default ();
-  NBThreadData *data = main_loop_force_nonblocking_data (loop);
   gsk_tree_insert (data->hook_tree, hook, hook);
   verify_nonblocking_data_has_source (data, loop);
 }
