--- Telegram/SourceFiles/data/data_document.cpp.orig	2019-07-07 13:34:35 UTC
+++ Telegram/SourceFiles/data/data_document.cpp
@@ -138,7 +138,7 @@ QString FileNameUnsafe(
 	name = name.replace(QRegularExpression(qsl("[\\\\\\/\\:\\*\\?\\\"\\<\\>\\|]")), qsl("_"));
 #elif defined Q_OS_MAC
 	name = name.replace(QRegularExpression(qsl("[\\:]")), qsl("_"));
-#elif defined Q_OS_LINUX
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD
 	name = name.replace(QRegularExpression(qsl("[\\/]")), qsl("_"));
 #endif
 	if (Global::AskDownloadPath() || savingAs) {
