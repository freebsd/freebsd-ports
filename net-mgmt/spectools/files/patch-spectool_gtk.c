--- spectool_gtk.c.orig	2014-06-10 21:22:30.000000000 +0200
+++ spectool_gtk.c	2014-06-10 21:22:51.000000000 +0200
@@ -182,7 +182,7 @@ static gboolean main_nodev_menu_button_p
 	GtkWidget *menu;
 	nb_aux *nbaux = (nb_aux *) aux;
 
-	g_return_if_fail(aux != NULL);
+	g_return_val_if_fail(aux != NULL, FALSE);
 
 	if (event->type == GDK_BUTTON_PRESS) {
 		GdkEventButton *bevent = (GdkEventButton *) event;
