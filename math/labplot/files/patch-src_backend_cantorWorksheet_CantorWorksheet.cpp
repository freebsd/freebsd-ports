--- src/backend/cantorWorksheet/CantorWorksheet.cpp.orig	2023-05-01 21:33:27 UTC
+++ src/backend/cantorWorksheet/CantorWorksheet.cpp
@@ -33,6 +33,9 @@
 #include <QModelIndex>
 
 #include <KLocalizedString>
+#include <KPluginLoader>
+#include <KPluginFactory>
+#include <KPluginMetaData>
 #include <KParts/ReadWritePart>
 
 CantorWorksheet::CantorWorksheet(const QString &name, bool loading)
