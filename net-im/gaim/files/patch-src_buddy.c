--- src/buddy.c.orig	Tue Apr  8 19:09:42 2003
+++ src/buddy.c	Tue Apr  8 19:09:47 2003
@@ -1132,6 +1132,7 @@
 	GtkWidget *sw;
 	GtkWidget *button;
 	GtkSizeGroup *sg;
+	GtkAccelGroup *accel_group;
 	GtkTreeSelection *selection;
 	GtkTargetEntry gte[] = {{"GAIM_BLIST_NODE", GTK_TARGET_SAME_APP, DRAG_ROW},
 				{"application/x-im-contact", 0, DRAG_BUDDY}};
@@ -1156,7 +1157,10 @@
 	gtk_widget_add_events(gtkblist->window, GDK_VISIBILITY_NOTIFY_MASK);
 
 	/******************************* Menu bar *************************************/
-	ift = gtk_item_factory_new(GTK_TYPE_MENU_BAR, "<GaimMain>", NULL);
+	accel_group = gtk_accel_group_new();
+	gtk_window_add_accel_group(GTK_WINDOW (gtkblist->window), accel_group);
+	g_object_unref(accel_group);
+	ift = gtk_item_factory_new(GTK_TYPE_MENU_BAR, "<GaimMain>", accel_group);
 	gtk_item_factory_set_translate_func (ift,
 					     item_factory_translate_func,
 					     NULL, NULL);
