--- src/pitivi-timelinecellrenderer.c.orig	Mon Dec 20 13:22:57 2004
+++ src/pitivi-timelinecellrenderer.c	Mon Dec 20 13:23:54 2004
@@ -744,12 +744,13 @@
 	  }
 	else
 	  {
+	    GtkWidget *linked_ref;
 	    gtk_container_remove (GTK_CONTAINER (parent), GTK_WIDGET (source));
 	    pitivi_add_to_layout (GTK_WIDGET (self),  source, x, 0);
 	    
 	    /* linked widget */
 	    
-	    GtkWidget *linked_ref = gtk_widget_ref (GTK_WIDGET (dragged->linked));
+	    linked_ref = gtk_widget_ref (GTK_WIDGET (dragged->linked));
 	    gtk_container_remove (GTK_CONTAINER (parent->linked_track), GTK_WIDGET (dragged->linked));
 	    pitivi_add_to_layout (GTK_WIDGET (self->linked_track), linked_ref, x, 0);
 	    gtk_widget_unref (linked_ref);
