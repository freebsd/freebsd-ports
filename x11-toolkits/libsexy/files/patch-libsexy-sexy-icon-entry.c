--- libsexy/sexy-icon-entry.c.orig	Fri Oct 14 10:48:10 2005
+++ libsexy/sexy-icon-entry.c	Tue Nov  8 21:09:27 2005
@@ -316,6 +316,8 @@
 
 	for (i = 0; i < MAX_ICONS; i++)
 	{
+		SexyIconInfo *icon_info;
+
 		attributes.window_type = GDK_WINDOW_CHILD;
 		attributes.wclass = GDK_INPUT_OUTPUT;
 		attributes.visual = gtk_widget_get_visual(widget);
@@ -329,7 +331,7 @@
 		attributes_mask = GDK_WA_X | GDK_WA_Y |
 		                  GDK_WA_VISUAL | GDK_WA_COLORMAP;
 
-		SexyIconInfo *icon_info = &entry->priv->icons[i];
+		icon_info = &entry->priv->icons[i];
 		icon_info->window = gdk_window_new(widget->window, &attributes,
 										   attributes_mask);
 		gdk_window_set_user_data(icon_info->window, widget);
