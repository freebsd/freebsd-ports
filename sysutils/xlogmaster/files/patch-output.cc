--- src/output.cc.orig	2007-08-12 19:13:18.000000000 +0200
+++ src/output.cc	2007-08-12 19:13:42.000000000 +0200
@@ -187,7 +187,7 @@
 gint 
 pipe_magic_interrupt(gpointer data)
 {
-  gint i = (gint) data;
+  glong i = (glong) data;
   
   /* are we locked out ? */
   if ( entry[i]->pipe_lock == TRUE )
