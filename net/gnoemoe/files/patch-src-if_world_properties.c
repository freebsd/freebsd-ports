--- src/if_world_properties.c.orig	Fri Jan 14 18:10:45 2005
+++ src/if_world_properties.c	Fri Jan 14 18:11:46 2005
@@ -117,6 +117,8 @@
 gboolean
 check_world_properties_values() {
 
+  world *ifWld, *newWld;
+
   GtkEntry *entry = GTK_ENTRY(if_world_properties_get_widget("entryName"));
   gchar *name = g_strdup(gtk_entry_get_text(entry));
   GtkEntry *entryHost = GTK_ENTRY(if_world_properties_get_widget("entryHost"));
@@ -125,8 +127,8 @@
   g_strstrip(name);
   g_strstrip(host);
 
-  world *ifWld = world_get_by_name(name);
-  world *newWld = world_properties_get_world();
+  ifWld = world_get_by_name(name);
+  newWld = world_properties_get_world();
 
   if (strlen(name) == 0) {
     GtkWidget *mDlg =
