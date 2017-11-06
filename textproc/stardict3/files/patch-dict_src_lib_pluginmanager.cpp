--- dict/src/lib/pluginmanager.cpp.orig	2017-04-02 22:22:40 UTC
+++ dict/src/lib/pluginmanager.cpp
@@ -96,7 +96,7 @@ void StarDictPlugins::load(const std::string& dirpath,
 {
 	std::list<std::string> plugins_dirs;
 	plugins_dirs.push_back(dirpath);
-	for_each_file(plugins_dirs, "."G_MODULE_SUFFIX, order_list, disable_list, PluginLoader(*this));
+	for_each_file(plugins_dirs, "." G_MODULE_SUFFIX, order_list, disable_list, PluginLoader(*this));
 }
 
 void StarDictPlugins::reorder(const std::list<std::string>& order_list)
@@ -184,7 +184,7 @@ void StarDictPlugins::get_plugin_list(const std::list<
 	std::list<std::string> plugins_dirs;
 	plugins_dirs.push_back(plugindirpath);
 	std::list<std::string> disable_list;
-	for_each_file(plugins_dirs, "."G_MODULE_SUFFIX, order_list, disable_list, PluginInfoLoader(*this, virtualdict_pluginlist, netdict_pluginlist, specialdict_pluginlist, tts_pluginlist, parsedata_pluginlist, misc_pluginlist));
+	for_each_file(plugins_dirs, "." G_MODULE_SUFFIX, order_list, disable_list, PluginInfoLoader(*this, virtualdict_pluginlist, netdict_pluginlist, specialdict_pluginlist, tts_pluginlist, parsedata_pluginlist, misc_pluginlist));
 
 	if (!virtualdict_pluginlist.empty()) {
 		plugin_list.push_back(std::pair<StarDictPlugInType, std::list<StarDictPluginInfo> >(StarDictPlugInType_VIRTUALDICT, virtualdict_pluginlist));
