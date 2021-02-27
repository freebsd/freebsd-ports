--- src/grg_menus.c.orig	2008-01-04 13:08:44 UTC
+++ src/grg_menus.c
@@ -31,6 +31,12 @@
 
 #include <gdk/gdkkeysyms.h>
 
+GtkWidget *bnew, *bopen, *bsave, *bsas, *brev, *bclose, *bquit;
+GtkWidget *badd, *brem, *bcut, *bcop, *bpaste, *bfind, *bfinda, *bpwd, *bpref;
+GtkWidget *bmfirst, *bmback, *bmfor, *bmlast, *bmind;
+GtkWidget *bwipe;
+GtkWidget *babo;
+
 #define NEW_MENU_ITEM(var, text, cb, data, parent, img, key, mod) \
 	var = gtk_image_menu_item_new_with_mnemonic(text); \
 	gtk_menu_shell_append (GTK_MENU_SHELL (parent), var); \
