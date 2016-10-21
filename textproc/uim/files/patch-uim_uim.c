--- uim/uim.c.orig	2013-06-30 04:26:09 UTC
+++ uim/uim.c
@@ -101,10 +101,10 @@ fatal_error_hook(void)
   uim_fatal_error("an unhandled error raised from Scheme interpreter");
 }
 
-int
+long
 uim_init(void)
 {
-  int ret;
+  long ret;
   char *sys_load_path;
 
   if (uim_initialized)
@@ -119,7 +119,7 @@ uim_init(void)
   uim_scm_init(sys_load_path);
   uim_scm_set_fatal_error_hook(fatal_error_hook);
 
-  ret = (int)uim_scm_call_with_gc_ready_stack((uim_gc_gate_func_ptr)uim_init_internal, NULL);
+  ret = (long)uim_scm_call_with_gc_ready_stack((uim_gc_gate_func_ptr)uim_init_internal, NULL);
 
   UIM_CATCH_ERROR_END();
 
