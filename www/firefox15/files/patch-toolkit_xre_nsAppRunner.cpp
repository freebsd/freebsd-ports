--- toolkit/xre/nsAppRunner.cpp.orig	Sat Jun 19 00:37:07 2004
+++ toolkit/xre/nsAppRunner.cpp	Sat Jun 19 00:37:39 2004
@@ -1710,6 +1710,7 @@
   // in nsAppShell::Create, but we need to get in before gtk
   // has been initialized to make sure everything is running
   // consistently.
+  g_thread_init(NULL);
   if (CheckArg("install"))
     gdk_rgb_set_install(TRUE);
 
