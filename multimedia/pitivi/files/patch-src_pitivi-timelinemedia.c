--- src/pitivi-timelinemedia.c.orig	Mon Dec 20 13:34:27 2004
+++ src/pitivi-timelinemedia.c	Mon Dec 20 13:37:47 2004
@@ -845,7 +845,7 @@
 					 GdkEventButton *event)
 {
   PitiviCursor *cursor;
-
+  gint x;
   PitiviTimelineMedia *this = PITIVI_TIMELINEMEDIA (widget);
   cursor = pitivi_getcursor_id (widget);
   if ((cursor->type == PITIVI_CURSOR_SELECT) && (event->button == 1))
@@ -874,7 +874,7 @@
       this->private->menu = GTK_WIDGET (pitivi_create_menupopup (widget, TimeItemPopup, iNbTimeItemPopup));
       gtk_menu_popup(GTK_MENU (this->private->menu), NULL, NULL, NULL, this, event->button, event->time);
     }
-  gint x = event->x;
+  x = event->x;
   if ( (x >= widget->allocation.width / 2 ) )
     this->resz = 0;
   else
@@ -1170,13 +1170,14 @@
 {
   if (!this->cutted)
     {
+      GtkWidget *w;
       this->cutted = TRUE;
       
       gtk_widget_hide (GTK_WIDGET(this));
       if (this->linked)
 	gtk_widget_hide (GTK_WIDGET (this->linked));
   
-      GtkWidget *w = gtk_widget_get_toplevel (GTK_WIDGET(this));
+      w = gtk_widget_get_toplevel (GTK_WIDGET(this));
       g_signal_emit_by_name (w, "copy-source", this);
     }
   else
@@ -1187,11 +1188,12 @@
 {
   if (!this->copied)
     {
+      GtkWidget *w;
       this->copied = TRUE;
       
       /* copy media */
       
-      GtkWidget *w = gtk_widget_get_toplevel (GTK_WIDGET(this));
+      w = gtk_widget_get_toplevel (GTK_WIDGET(this));
       g_signal_emit_by_name (w, "copy-source", this);
     }
   else
