--- ./src/jagsmountwithcommand.h.orig	2003-09-04 23:14:54.000000000 +0200
+++ ./src/jagsmountwithcommand.h	2014-01-08 10:20:11.000000000 +0100
@@ -45,5 +45,7 @@
   ~JagsMountWithCommand();
 };
 
+gint on_mount_with_command_ok(GtkWidget *, JagsMountWithCommand *);
+gint on_mount_with_command_cancel(GtkWidget *, JagsMountWithCommand *);
 
 #endif
