--- gui/syntaxhighlighter.cpp.orig	2020-04-29 20:42:12 UTC
+++ gui/syntaxhighlighter.cpp
@@ -128,7 +128,7 @@ ColorScheme ColorScheme::loadFromFile(const QString& p
 ColorScheme ColorScheme::loadByName(const QString& name)
 {
     for (auto& path : colorSchemeSearchPaths()) {
-        auto fileName = QString("%1/%2.%3").arg(path, name, m_colorSchemeExtension);
+        auto fileName = QString("%1/%2.%3").arg(path).arg(name).arg(m_colorSchemeExtension);
         auto colorScheme = loadFromFile(fileName);
         if (colorScheme.isValid())
             return colorScheme;
