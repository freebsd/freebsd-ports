--- src/prefs_account.c.orig	Tue Aug 17 14:34:51 2004
+++ src/prefs_account.c	Tue Aug 17 14:35:30 2004
@@ -1149,6 +1149,7 @@
 		gtk_option_menu_set_history(optmenu, 3);
 		break;
 	default:
+		break;
 	}
 
 	menu = gtk_option_menu_get_menu(optmenu);
@@ -1203,6 +1204,7 @@
 		gtk_option_menu_set_history(optmenu, 2);
 		break;
 	default:
+		break;
 	}
 	menu = gtk_option_menu_get_menu(optmenu);
 	menuitem = gtk_menu_get_active(GTK_MENU(menu));
