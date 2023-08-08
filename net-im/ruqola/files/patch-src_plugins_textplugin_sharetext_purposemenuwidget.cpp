--- src/plugins/textplugin/sharetext/purposemenuwidget.cpp.orig	2023-01-31 13:04:44 UTC
+++ src/plugins/textplugin/sharetext/purposemenuwidget.cpp
@@ -5,10 +5,15 @@
 */
 
 #include "purposemenuwidget.h"
+#include "purpose_version.h"
 #include <KLocalizedString>
 #include <KMessageBox>
 #include <Purpose/AlternativesModel>
+#if PURPOSE_VERSION < QT_VERSION_CHECK(5, 104, 0)
 #include <PurposeWidgets/Menu>
+#else
+#include <Purpose/Menu>
+#endif
 #include <QJsonArray>
 #include <QTemporaryFile>
 #include <QUrl>
