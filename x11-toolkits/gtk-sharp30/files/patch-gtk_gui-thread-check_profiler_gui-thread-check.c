--- gtk/gui-thread-check/profiler/gui-thread-check.c.orig	2018-06-11 18:44:28 UTC
+++ gtk/gui-thread-check/profiler/gui-thread-check.c
@@ -93,6 +93,5 @@ mono_profiler_startup (const char *desc)
 	
 	mono_profiler_install (NULL, NULL);
 	mono_profiler_install_enter_leave (simple_method_enter, NULL);
-	mono_profiler_set_events (MONO_PROFILE_ENTER_LEAVE);
 }
 
