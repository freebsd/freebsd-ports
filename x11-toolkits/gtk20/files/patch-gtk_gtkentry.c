--- gtk/gtkentry.c.orig	Wed Aug 25 12:44:23 2004
+++ gtk/gtkentry.c	Wed Aug 25 12:44:52 2004
@@ -1670,8 +1670,9 @@
 				    event->x + entry->scroll_offset, event->y))
 	{
 	  GdkDragContext *context;
+	  guint actions;
 	  GtkTargetList *target_list = gtk_target_list_new (NULL, 0);
-	  guint actions = entry->editable ? GDK_ACTION_COPY | GDK_ACTION_MOVE : GDK_ACTION_COPY;
+	  actions = entry->editable ? GDK_ACTION_COPY | GDK_ACTION_MOVE : GDK_ACTION_COPY;
 
 	  gtk_target_list_add_text_targets (target_list);
 
