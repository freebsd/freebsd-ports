--- kadu-core/themes.cpp.orig	2016-10-19 17:11:40 UTC
+++ kadu-core/themes.cpp
@@ -164,7 +164,7 @@ QStringList Themes::defaultPathsProvider
 {
 	QStringList result;
 
-	auto path = QString{m_pathsProvider->dataPath() + QStringLiteral("themes/") + Name};
+	auto path = QString(m_pathsProvider->dataPath() + QStringLiteral("themes/") + Name);
 	foreach(const QString &it, getSubDirs(path))
 		result << (path + '/' + it + '/');
 
