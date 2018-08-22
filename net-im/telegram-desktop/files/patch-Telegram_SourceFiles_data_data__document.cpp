--- Telegram/SourceFiles/data/data_document.cpp.orig	2018-08-04 18:53:40 UTC
+++ Telegram/SourceFiles/data/data_document.cpp
@@ -77,7 +77,7 @@ QString FileNameUnsafe(
 	name = name.replace(QRegularExpression(qsl("[\\\\\\/\\:\\*\\?\\\"\\<\\>\\|]")), qsl("_"));
 #elif defined Q_OS_MAC
 	name = name.replace(QRegularExpression(qsl("[\\:]")), qsl("_"));
-#elif defined Q_OS_LINUX
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD
 	name = name.replace(QRegularExpression(qsl("[\\/]")), qsl("_"));
 #endif
 	if (Global::AskDownloadPath() || savingAs) {
