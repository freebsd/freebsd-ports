--- kadu-core/plugin/metadata/plugin-metadata-finder.cpp.orig	2014-12-04 20:24:51 UTC
+++ kadu-core/plugin/metadata/plugin-metadata-finder.cpp
@@ -48,7 +48,7 @@ void PluginMetadataFinder::setPluginMeta
 std::map<QString, PluginMetadata> PluginMetadataFinder::provide() noexcept
 {
 	if (m_directory.isEmpty() || !m_pluginMetadataReader)
-		return {};
+		return std::map<QString, PluginMetadata>{};
 
 	auto result = std::map<QString, PluginMetadata>{};
 
