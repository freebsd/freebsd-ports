--- programs/table/gchemtable-main.cc.orig	2009-05-03 13:57:28.000000000 -0400
+++ programs/table/gchemtable-main.cc	2009-05-03 13:57:35.000000000 -0400
@@ -41,7 +41,7 @@ int main (int argc, char *argv[])
 	GSList *l = NULL;
 	l = g_slist_append (l, (void *) "GOffice_plot_xy");
 	l = g_slist_append (l, (void *) "GOffice_reg_linear");
-	go_plugins_init (NULL, NULL, l, NULL, FALSE, GO_PLUGIN_LOADER_MODULE_TYPE);
+	go_plugins_init (NULL, NULL, l, NULL, FALSE, GO_TYPE_PLUGIN_LOADER_MODULE);
 	g_slist_free (l);
 
 	gtk_main();
