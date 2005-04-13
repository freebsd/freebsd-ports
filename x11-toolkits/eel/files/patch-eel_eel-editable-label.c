--- eel/eel-editable-label.c.orig	Mon Mar 21 06:20:09 2005
+++ eel/eel-editable-label.c	Mon Mar 21 06:20:12 2005
@@ -3998,7 +3998,10 @@
 static gboolean
 eel_editable_label_accessible_idle_notify_insert (gpointer data)
 {
+  GDK_THREADS_ENTER ();
   eel_editable_label_accessible_notify_insert (data);
+  GDK_THREADS_LEAVE ();
+
   return FALSE;
 }
 
