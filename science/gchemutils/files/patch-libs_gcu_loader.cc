--- libs/gcu/loader.cc.orig	2009-05-03 13:49:58.000000000 -0400
+++ libs/gcu/loader.cc	2009-05-03 13:51:06.000000000 -0400
@@ -122,7 +122,7 @@ plugin_service_chemical_loader_init (Plu
 
 GSF_CLASS (PluginServiceChemicalLoader, plugin_service_chemical_loader,
            plugin_service_chemical_loader_class_init, plugin_service_chemical_loader_init,
-           GO_PLUGIN_SERVICE_SIMPLE_TYPE)
+           GO_TYPE_PLUGIN_SERVICE_SIMPLE)
 
 Loader::Loader ()
 {
@@ -143,7 +143,7 @@ void Loader::Init ()
 	go_plugin_loader_module_register_version ("gchemutils", VERSION);
 	char *plugins_dir = g_strdup (GCU_PLUGINS_DIR);
 	GSList *dirs = g_slist_prepend (NULL, plugins_dir);
-	go_plugins_init (gcu_get_cmd_context (), NULL, NULL, dirs, true, GO_PLUGIN_LOADER_MODULE_TYPE);
+	go_plugins_init (gcu_get_cmd_context (), NULL, NULL, dirs, true, GO_TYPE_PLUGIN_LOADER_MODULE);
 	g_slist_free (dirs);
 	g_free (plugins_dir);
 	Inited = true;
