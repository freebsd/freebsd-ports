--- src/gnome-keyring-manager-util.c.orig	Mon Jul 12 23:12:27 2004
+++ src/gnome-keyring-manager-util.c	Mon Jul 12 23:13:00 2004
@@ -189,8 +189,6 @@
   GtkIconTheme *icon_theme;
   GdkPixbuf *pixbuf;
 
-  g_return_val_if_fail (GTK_IS_WINDOW (transient_parent), NULL);
-
   const char *authors[] = {
     "Fernando Herrera <fherrera@onirica.com>",
     "Mariano Su\303\241rez-Alvarez <mariano@gnome.org>",
@@ -201,6 +199,8 @@
   };
   const char *translator_credits = _("translator_credits");
   
+  g_return_val_if_fail (GTK_IS_WINDOW (transient_parent), NULL);
+
   icon_theme = gtk_icon_theme_get_default ();
   pixbuf = gtk_icon_theme_load_icon (icon_theme, "stock_keyring", 48, 0, NULL);
 	   
