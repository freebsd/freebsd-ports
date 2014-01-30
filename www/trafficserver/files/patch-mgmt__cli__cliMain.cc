--- ./mgmt/cli/cliMain.cc.orig	2013-12-05 22:07:48.000000000 +0000
+++ ./mgmt/cli/cliMain.cc	2014-01-27 08:45:49.000000000 +0000
@@ -87,6 +87,7 @@
   register_event_callback();
 
 #if HAVE_LIBREADLINE
+  Tcl_FindExecutable(NULL);
   Tcl_SetMainLoop(Tcl_ReadlineMain);
 #endif
 
