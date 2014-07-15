--- ./uget-gtk/UgApp-gtk-gui.c.orig	2014-07-12 12:11:05.000000000 +0000
+++ ./uget-gtk/UgApp-gtk-gui.c	2014-07-12 12:12:47.000000000 +0000
@@ -860,12 +860,14 @@
 	gtk_menu_shell_append ((GtkMenuShell*)menu, menu_item);
 	menubar->help.report_bug = menu_item;
 
+	/*
 	// Check for Updates
 	menu_item = gtk_image_menu_item_new_with_mnemonic(_("Check for Updates"));
 //	image = gtk_image_new_from_stock (GTK_STOCK_DND_MULTIPLE, GTK_ICON_SIZE_MENU);
 //	gtk_image_menu_item_set_image ((GtkImageMenuItem*)menu_item, image);
 	gtk_menu_shell_append ((GtkMenuShell*)menu, menu_item);
 	menubar->help.check_updates = menu_item;
+	*/
 
 	// About Uget
 	menu_item = gtk_image_menu_item_new_from_stock (GTK_STOCK_ABOUT, NULL);
