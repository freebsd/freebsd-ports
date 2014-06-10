--- spectool_gtk_widget.c.orig	2014-06-10 21:07:11.000000000 +0200
+++ spectool_gtk_widget.c	2014-06-10 21:09:56.000000000 +0200
@@ -184,8 +184,8 @@ static gboolean spectool_widget_menu_but
 	SpectoolWidgetController *con = (SpectoolWidgetController *) widget;
 	char alt_title_text[32];
 
-	g_return_if_fail(widget != NULL);
-	g_return_if_fail(event != NULL);
+	g_return_val_if_fail(widget != NULL, FALSE);
+	g_return_val_if_fail(event != NULL, FALSE);
 
 	if (event->type == GDK_BUTTON_PRESS) {
 		GdkEventButton *bevent = (GdkEventButton *) event;
@@ -231,8 +231,8 @@ SpectoolWidgetController *spectool_widge
 	GdkColor c;
 	GtkStyle *style;
 
-	g_return_if_fail(widget != NULL);
-	g_return_if_fail(IS_SPECTOOL_WIDGET(widget));
+	g_return_val_if_fail(widget != NULL, NULL);
+	g_return_val_if_fail(IS_SPECTOOL_WIDGET(widget), NULL);
 
 	wwidget = SPECTOOL_WIDGET(widget);
 
@@ -294,9 +294,9 @@ gint spectool_widget_mouse_click(GtkWidg
 	GtkWidget *menu;
 	GdkEvent *event = (GdkEvent *) button;
 
-	g_return_if_fail(widget != NULL);
-	g_return_if_fail(aux != NULL);
-	g_return_if_fail(IS_SPECTOOL_WIDGET(aux));
+	g_return_val_if_fail(widget != NULL, 0);
+	g_return_val_if_fail(aux != NULL, 0);
+	g_return_val_if_fail(IS_SPECTOOL_WIDGET(aux), 0);
 
 	wwidget = SPECTOOL_WIDGET(aux);
 
@@ -780,8 +780,8 @@ static gint spectool_widget_expose(GtkWi
 	SpectoolWidget *wwidget;
 	cairo_t *cr;
 
-	g_return_if_fail(widget != NULL);
-	g_return_if_fail(IS_SPECTOOL_WIDGET(aux));
+	g_return_val_if_fail(widget != NULL, 0);
+	g_return_val_if_fail(IS_SPECTOOL_WIDGET(aux), 0);
 	wwidget = SPECTOOL_WIDGET(aux);
 
 	cr = gdk_cairo_create(widget->window);
