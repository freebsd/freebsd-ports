--- Telegram/lib_ui/ui/style/style_core_font.cpp.orig	2020-02-10 08:12:05 UTC
+++ Telegram/lib_ui/ui/style/style_core_font.cpp
@@ -22,7 +22,7 @@ void style_InitFontsResource() {
 	Q_INIT_RESOURCE(win);
 #elif defined Q_OS_MAC // Q_OS_WIN
 	Q_INIT_RESOURCE(mac);
-#elif defined Q_OS_LINUX && !defined DESKTOP_APP_USE_PACKAGED // Q_OS_WIN || Q_OS_MAC
+#elif (defined Q_OS_LINUX || defined Q_OS_FREEBSD) && !defined DESKTOP_APP_USE_PACKAGED // Q_OS_WIN || Q_OS_MAC
 	Q_INIT_RESOURCE(linux);
 #endif // Q_OS_WIN || Q_OS_MAC || (Q_OS_LINUX && !DESKTOP_APP_USE_PACKAGED)
 }
