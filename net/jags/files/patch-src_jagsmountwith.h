--- ./src/jagsmountwith.h.orig	2003-09-04 23:14:54.000000000 +0200
+++ ./src/jagsmountwith.h	2014-01-08 10:20:11.000000000 +0100
@@ -50,4 +50,7 @@
   void browse(void);
 };
 
+gint on_mount_with_ok(GtkWidget *, JagsMountWith *);
+gint on_mount_with_cancel(GtkWidget *, JagsMountWith *);
+
 #endif
