--- capplets/keyboard/gnome-keyboard-properties-xkbot.c.orig	Wed Jul 27 13:48:58 2005
+++ capplets/keyboard/gnome-keyboard-properties-xkbot.c	Wed Jul 27 13:49:37 2005
@@ -265,11 +265,12 @@
                                          GladeXML * dialog)
 {
   GtkWidget *expander, *align, *vbox;
+  gchar *utfGroupName, *titlemarkup;
 
   GSList * expanders_list = g_object_get_data (G_OBJECT (dialog), EXPANDERS_PROP);
 
-  gchar *utfGroupName = xci_desc_to_utf8 (configItem);
-  gchar *titlemarkup = g_strconcat ("<span>", utfGroupName, "</span>", NULL);
+  utfGroupName = xci_desc_to_utf8 (configItem);
+  titlemarkup = g_strconcat ("<span>", utfGroupName, "</span>", NULL);
 
   expander = gtk_expander_new (titlemarkup);
   g_object_set_data_full (G_OBJECT (expander), "utfGroupName", utfGroupName, g_free);
