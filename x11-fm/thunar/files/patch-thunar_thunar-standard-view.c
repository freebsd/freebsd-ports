Right click context menu with wrong icon (bug #10652)

--- thunar/thunar-standard-view.c.orig	2014-12-20 00:21:57 UTC
+++ thunar/thunar-standard-view.c
@@ -393,7 +393,7 @@ static const GtkActionEntry action_entri
 {
   { "file-context-menu", NULL, N_ ("File Context Menu"), NULL, NULL, NULL, },
   { "folder-context-menu", NULL, N_ ("Folder Context Menu"), NULL, NULL, NULL, },
-  { "create-folder", NULL, N_ ("Create _Folder..."), "<control><shift>N", N_ ("Create an empty folder within the current folder"), G_CALLBACK (thunar_standard_view_action_create_folder), },
+  { "create-folder", "folder-new", N_ ("Create _Folder..."), "<control><shift>N", N_ ("Create an empty folder within the current folder"), G_CALLBACK (thunar_standard_view_action_create_folder), },
   { "properties", GTK_STOCK_PROPERTIES, N_ ("_Properties..."), "<alt>Return", N_ ("View the properties of the selected file"), G_CALLBACK (thunar_standard_view_action_properties), },
   { "cut", GTK_STOCK_CUT, N_ ("Cu_t"), NULL, NULL, G_CALLBACK (thunar_standard_view_action_cut), },
   { "copy", GTK_STOCK_COPY, N_ ("_Copy"), NULL, NULL, G_CALLBACK (thunar_standard_view_action_copy), },
