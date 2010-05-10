--- src/account-setup-eplugin/exchange-mapi-account-setup.c.orig	2010-03-08 04:03:24.000000000 -0500
+++ src/account-setup-eplugin/exchange-mapi-account-setup.c	2010-03-13 17:49:17.000000000 -0500
@@ -696,3 +696,21 @@ exchange_mapi_cal_commit (EPlugin *epl, 
 	// Update the folder list in the plugin and ExchangeMAPIFolder
 	return;
 }
+
+const char *g_module_check_init (gpointer module);
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
