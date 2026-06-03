--- linphone-app/src/components/other/clipboard/Clipboard.cpp.orig	2025-12-26 08:11:45 UTC
+++ linphone-app/src/components/other/clipboard/Clipboard.cpp
@@ -56,7 +56,7 @@ QString Clipboard::getChatFormattedText () const {
 	QString text = getText();
 	if (text.isEmpty())
 		return text;
-#ifdef __linux__
+#if defined(__linux__ ) || defined(__FreeBSD__)
 	QString cr = "\n";
 #endif
 #ifdef WIN32
