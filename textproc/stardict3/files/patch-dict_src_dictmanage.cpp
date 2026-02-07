--- dict/src/dictmanage.cpp.orig	2017-04-02 22:24:23 UTC
+++ dict/src/dictmanage.cpp
@@ -77,7 +77,7 @@ static void get_all_plugin_list(std::list<DictItemId> 
 	std::list<std::string> plugin_disable_list;
 	std::list<std::string> plugins_dirs;
 	plugins_dirs.push_back(conf_dirs->get_plugin_dir());
-	for_each_file(plugins_dirs, "."G_MODULE_SUFFIX, plugin_order_list,
+	for_each_file(plugins_dirs, "." G_MODULE_SUFFIX, plugin_order_list,
 		plugin_disable_list, GetAllPluginList(plugin_all_list));
 }
 
