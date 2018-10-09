--- Telegram/SourceFiles/data/data_document.cpp.orig	2018-09-28 13:08:38 UTC
+++ Telegram/SourceFiles/data/data_document.cpp
@@ -78,7 +78,7 @@ QString FileNameUnsafe(
 	name = name.replace(QRegularExpression(qsl("[\\\\\\/\\:\\*\\?\\\"\\<\\>\\|]")), qsl("_"));
 #elif defined Q_OS_MAC
 	name = name.replace(QRegularExpression(qsl("[\\:]")), qsl("_"));
-#elif defined Q_OS_LINUX
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD
 	name = name.replace(QRegularExpression(qsl("[\\/]")), qsl("_"));
 #endif
 	if (Global::AskDownloadPath() || savingAs) {
