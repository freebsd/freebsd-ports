--- capplets/keyboard/gnome-keyboard-properties-xkbot.c.orig	Wed Jan 19 18:16:13 2005
+++ capplets/keyboard/gnome-keyboard-properties-xkbot.c	Wed Feb  9 21:33:00 2005
@@ -242,21 +242,25 @@
                                          Bool allowMultipleSelection,
                                          GladeXML * dialog)
 {
+  gchar *utfGroupName, *titlemarkup;
+  GtkWidget *expander;
+  GtkWidget *vbox;
+  GtkWidget *align;
   GSList * expanders_list = g_object_get_data (G_OBJECT (dialog), EXPANDERS_PROP);
 
   current1stLevelId = configItem->name;
 
-  gchar *utfGroupName = xci_desc_to_utf8 (configItem);
-  gchar *titlemarkup = g_strconcat ("<span>", utfGroupName, "</span>", NULL);
+  utfGroupName = xci_desc_to_utf8 (configItem);
+  titlemarkup = g_strconcat ("<span>", utfGroupName, "</span>", NULL);
 
-  GtkWidget *expander = gtk_expander_new (titlemarkup);
+  expander = gtk_expander_new (titlemarkup);
   g_object_set_data_full (G_OBJECT (expander), "utfGroupName", utfGroupName, g_free);
 
   g_free (titlemarkup);
   gtk_expander_set_use_markup (GTK_EXPANDER (expander), TRUE);
-  GtkWidget *align = gtk_alignment_new (0, 0, 1, 1);
+  align = gtk_alignment_new (0, 0, 1, 1);
   gtk_alignment_set_padding (GTK_ALIGNMENT (align), 6, 12, 12, 0);
-  GtkWidget *vbox = gtk_vbox_new (TRUE, 6);
+  vbox = gtk_vbox_new (TRUE, 6);
   gtk_container_add (GTK_CONTAINER (align), vbox);
   gtk_container_add (GTK_CONTAINER (expander), align);
   currentVbox = vbox;
