--- kadu-core/plugin/plugin-conflict-resolver.cpp.orig	2014-12-04 20:28:55 UTC
+++ kadu-core/plugin/plugin-conflict-resolver.cpp
@@ -40,7 +40,7 @@ void PluginConflictResolver::setPluginDe
 std::set<QString> PluginConflictResolver::conflictingPlugins(const std::set<QString> &activePluginSet, const QString &pluginName)
 {
 	if (!m_pluginDependencyHandler || contains(activePluginSet, pluginName))
-		return {};
+		return std::set<QString>{}; 
 
 	auto withDependencies = m_pluginDependencyHandler->withDependencies(pluginName);
 	auto withoutActive = decltype(withDependencies){};
