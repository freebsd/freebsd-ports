--- src/ephy-window.c.orig	2018-03-27 15:41:00 UTC
+++ src/ephy-window.c
@@ -1301,13 +1301,6 @@ webkit_context_menu_item_new_from_gaction_with_paramet
 #pragma GCC diagnostic pop
 }
 
-static WebKitContextMenuItem *
-webkit_context_menu_item_new_from_gaction (GAction    *action,
-                                           const char *label)
-{
-  return webkit_context_menu_item_new_from_gaction_with_parameter (action, label, NULL);
-}
-
 static char *
 ellipsize_string (const char *string,
                   glong       max_length)
@@ -1380,7 +1373,7 @@ add_action_to_context_menu (WebKitContextMenu *context
   action = g_action_map_lookup_action (G_ACTION_MAP (action_group), name);
   label = g_hash_table_lookup (window->action_labels, name);
   if (strcmp (label, "search-selection-placeholder") != 0) {
-    webkit_context_menu_append (context_menu, webkit_context_menu_item_new_from_gaction (action, _(label)));
+    webkit_context_menu_append (context_menu, webkit_context_menu_item_new_from_gaction_with_parameter (action, _(label), NULL));
   } else {
     search_term = g_variant_get_string (target, NULL);
     search_label = format_search_label (search_term);
