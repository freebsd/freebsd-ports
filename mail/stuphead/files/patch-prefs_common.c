--- src/prefs_common.c.bak	Tue Aug 17 14:33:52 2004
+++ src/prefs_common.c	Tue Aug 17 14:34:10 2004
@@ -2789,6 +2789,7 @@
 		gtk_option_menu_set_history(optmenu, 5);
 		break;
 	default:
+		break;
 	}
 	menu = gtk_option_menu_get_menu(optmenu);
 	menuitem = gtk_menu_get_active(GTK_MENU(menu));
