--- spectool_gtk_planar.c.orig	2014-06-10 21:16:11.000000000 +0200
+++ spectool_gtk_planar.c	2014-06-10 21:17:52.000000000 +0200
@@ -351,15 +351,15 @@ static gint spectool_planar_button_press
 	SpectoolWidget *wwidget;
 	int ch;
 
-	g_return_if_fail(aux != NULL);
-	g_return_if_fail(IS_SPECTOOL_PLANAR(aux));
-	g_return_if_fail(IS_SPECTOOL_WIDGET(aux));
+	g_return_val_if_fail(aux != NULL, 0);
+	g_return_val_if_fail(IS_SPECTOOL_PLANAR(aux), 0);
+	g_return_val_if_fail(IS_SPECTOOL_WIDGET(aux), 0);
 
 	planar = SPECTOOL_PLANAR(aux);
 	wwidget = SPECTOOL_WIDGET(aux);
 
-	g_return_if_fail(wwidget->sweepcache != NULL);
-	g_return_if_fail(wwidget->sweepcache->avg != NULL);
+	g_return_val_if_fail(wwidget->sweepcache != NULL, 0);
+	g_return_val_if_fail(wwidget->sweepcache->avg != NULL, 0);
 
 	if (event->button != 1)
 		return TRUE;
@@ -379,15 +379,15 @@ static gboolean spectool_planar_mouse_mo
 	SpectoolPlanar *planar;
 	SpectoolWidget *wwidget;
 
-	g_return_if_fail(aux != NULL);
-	g_return_if_fail(IS_SPECTOOL_PLANAR(aux));
-	g_return_if_fail(IS_SPECTOOL_WIDGET(aux));
+	g_return_val_if_fail(aux != NULL, FALSE);
+	g_return_val_if_fail(IS_SPECTOOL_PLANAR(aux), FALSE);
+	g_return_val_if_fail(IS_SPECTOOL_WIDGET(aux), FALSE);
 
 	planar = SPECTOOL_PLANAR(aux);
 	wwidget = SPECTOOL_WIDGET(aux);
 
-	g_return_if_fail(wwidget->sweepcache != NULL);
-	g_return_if_fail(wwidget->sweepcache->avg != NULL);
+	g_return_val_if_fail(wwidget->sweepcache != NULL, FALSE);
+	g_return_val_if_fail(wwidget->sweepcache->avg != NULL, FALSE);
 
 	if (event->is_hint) {
 		gdk_window_get_pointer(event->window, &x, &y, &state);
