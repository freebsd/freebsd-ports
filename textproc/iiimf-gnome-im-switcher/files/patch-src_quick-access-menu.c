--- src/quick-access-menu.c.orig	Fri Jul 16 00:32:39 2004
+++ src/quick-access-menu.c	Wed Oct 13 23:01:48 2004
@@ -279,9 +279,9 @@
 	  GtkWidget *le_submenu;
 	  GtkWidget *le_submenu_item;
 	  GSList *legroup = NULL;
+	  int i, len;
 
 	  le_submenu = gtk_menu_new ();
-	  int i, len;
 	  len = g_list_length (lelist);
 	  le_submenu_item = gtk_radio_menu_item_new_with_label (legroup, lelist->data);
 	  legroup = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (le_submenu_item));
