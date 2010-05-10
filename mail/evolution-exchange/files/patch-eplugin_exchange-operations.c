--- eplugin/exchange-operations.c.orig	2010-03-07 20:00:49.000000000 -0500
+++ eplugin/exchange-operations.c	2010-03-13 17:47:23.000000000 -0500
@@ -304,3 +304,21 @@ is_exchange_personal_folder (ExchangeAcc
 	}
 	return FALSE;
 }
+
+const char * g_module_check_init (gpointer module);
+const char *
+g_module_check_init (gpointer module) {
+	return NULL;
+}
+
+void g_module_unload (gpointer module);
+void
+g_module_unload (gpointer module) {
+	return;
+}
+
+GtkWidget *e_plugin_lib_get_configure_widget (EPlugin *plugin);
+GtkWidget *
+e_plugin_lib_get_configure_widget (EPlugin *plugin) {
+	return NULL;
+}
