--- src/if_worlds_listing.c.orig	Fri Sep 10 23:56:49 2004
+++ src/if_worlds_listing.c	Fri Jan 14 18:06:02 2005
@@ -149,6 +149,7 @@
   GtkTreeIter iter;
   GtkTreeModel *tvwModel;
   gchar *name;
+  world *wld;
 
   gboolean isActive = gtk_cell_renderer_toggle_get_active(cell);
 
@@ -159,7 +160,7 @@
   gtk_tree_model_get_iter_from_string(tvwModel, &iter, path_string);
   gtk_tree_model_get(tvwModel, &iter, NAME_COLUMN, &name, -1);
 
-  world *wld = world_get_by_name(name);
+  wld = world_get_by_name(name);
 
   g_free(name);
   options_set_int(wld->settings, "autoload", !isActive);
@@ -293,9 +294,10 @@
   gchar *name;
 
   if (firstPath) {
+    world *wld;
     gtk_tree_model_get_iter(model, &iter, firstPath->data);
     gtk_tree_model_get(model, &iter, NAME_COLUMN, &name, -1);
-    world *wld = world_get_by_name(name);
+    wld = world_get_by_name(name);
 
     g_free(name);
 
@@ -328,12 +330,13 @@
   gint result;
 
   if (firstPath) {
+    world *wld, *newWld;
     gtk_tree_model_get_iter(model, &iter, firstPath->data);
     gtk_tree_model_get(model, &iter, NAME_COLUMN, &name, -1);
-    world *wld = world_get_by_name(name);
+    wld = world_get_by_name(name);
 
     // now duplicate the world
-    world *newWld = world_copy(wld);
+    newWld = world_copy(wld);
 
     // Make sure that we set the path to NULL, because otherwise it would look like
     // a modifying of the source world, we don't want that! Setting it to NULL will
