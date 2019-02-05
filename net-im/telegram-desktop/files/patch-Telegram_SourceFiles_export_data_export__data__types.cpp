--- Telegram/SourceFiles/export/data/export_data_types.cpp.orig	2019-02-01 12:51:46 UTC
+++ Telegram/SourceFiles/export/data/export_data_types.cpp
@@ -369,9 +369,9 @@ QString CleanDocumentName(QString name) {
 		'|',
 #elif defined Q_OS_MAC // Q_OS_WIN
 		':',
-#elif defined Q_OS_LINUX // Q_OS_WIN || Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_WIN || Q_OS_MAC
 		'/',
-#endif // Q_OS_WIN || Q_OS_MAC || Q_OS_LINUX
+#endif // Q_OS_WIN || Q_OS_MAC || Q_OS_LINUX || Q_OS_FREEBSD
 	};
 	for (const auto ch : controls) {
 		name = std::move(name).replace(ch, '_');
