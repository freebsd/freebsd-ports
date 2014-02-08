--- gtk/gtkselection.c.orig	2014-02-03 22:40:05.000000000 +0100
+++ gtk/gtkselection.c	2014-02-03 22:40:43.000000000 +0100
@@ -2294,7 +2294,7 @@ _gtk_selection_request (GtkWidget *widge
   gulong selection_max_size;
 
   if (event->requestor == NULL)
-    return;
+    return FALSE;
 
   if (initialize)
     gtk_selection_init ();
