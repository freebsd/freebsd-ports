--- Telegram/SourceFiles/structs.cpp.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/structs.cpp
@@ -1280,7 +1280,7 @@ QString saveFileName(const QString &titl
 	name = name.replace(QRegularExpression(qsl("[\\\\\\/\\:\\*\\?\\\"\\<\\>\\|]")), qsl("_"));
 #elif defined Q_OS_MAC
 	name = name.replace(QRegularExpression(qsl("[\\:]")), qsl("_"));
-#elif defined Q_OS_LINUX
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD
 	name = name.replace(QRegularExpression(qsl("[\\/]")), qsl("_"));
 #endif
 	if (Global::AskDownloadPath() || savingAs) {
