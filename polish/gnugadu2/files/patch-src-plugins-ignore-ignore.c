--- src/plugins/ignore/ignore.c.orig	Mon Dec 27 10:44:34 2004
+++ src/plugins/ignore/ignore.c	Fri Jan 28 00:41:57 2005
@@ -102,10 +102,11 @@
 				{
 				case GGADU_IGNORE_ADD_ID:
 					{
+						gchar *ignored_list_prev;
+						gchar *ignored_list_after = NULL;
 						GGaduContact *k = g_new0(GGaduContact, 1);
 						k->id = g_strdup(kv->value);
-						gchar *ignored_list_prev = ggadu_config_var_get(ignore_handler, "list");
-						gchar *ignored_list_after = NULL;
+						ignored_list_prev = ggadu_config_var_get(ignore_handler, "list");
 
 						ignored_list_after = ggadu_add_ignored_contact(ignored_list_prev, k);
 						if (ignored_list_after)
@@ -142,10 +143,11 @@
 				{
 				case GGADU_IGNORE_REMOVE_ID:
 					{
+						gchar *ignored_list_prev;
+						gchar *ignored_list_after = NULL;
 						GGaduContact *k = g_new0(GGaduContact, 1);
 						k->id = g_strdup(kv->value);
-						gchar *ignored_list_prev = ggadu_config_var_get(ignore_handler, "list");
-						gchar *ignored_list_after = NULL;
+						ignored_list_prev = ggadu_config_var_get(ignore_handler, "list");
 
 						ignored_list_after = ggadu_remove_ignored_contact(ignored_list_prev, k);
 						if (ignored_list_after)
