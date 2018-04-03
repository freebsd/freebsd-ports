--- ui-gtk/UgtkMenubar-ui.c.orig	2018-01-08 00:04:26 UTC
+++ ui-gtk/UgtkMenubar-ui.c
@@ -745,13 +745,6 @@ static void ugtk_menubar_help_init (Ugtk
 	gtk_menu_shell_append ((GtkMenuShell*)menu, menu_item);
 	menubar->help.keyboard_shortcuts = menu_item;
 
-	// Check for Updates
-	menu_item = gtk_image_menu_item_new_with_mnemonic(_("Check for Updates"));
-//	image = gtk_image_new_from_stock (GTK_STOCK_DND_MULTIPLE, GTK_ICON_SIZE_MENU);
-//	gtk_image_menu_item_set_image ((GtkImageMenuItem*)menu_item, image);
-	gtk_menu_shell_append ((GtkMenuShell*)menu, menu_item);
-	menubar->help.check_updates = menu_item;
-
 	// About Uget
 	menu_item = gtk_image_menu_item_new_from_stock (GTK_STOCK_ABOUT, NULL);
 	gtk_menu_shell_append ((GtkMenuShell*)menu, menu_item);
