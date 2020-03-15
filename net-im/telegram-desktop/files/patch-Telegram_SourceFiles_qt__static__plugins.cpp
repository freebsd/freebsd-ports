--- Telegram/SourceFiles/qt_static_plugins.cpp.orig	2020-02-18 08:28:06 UTC
+++ Telegram/SourceFiles/qt_static_plugins.cpp
@@ -19,7 +19,7 @@ Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
 #elif defined Q_OS_MAC // Q_OS_WIN
 Q_IMPORT_PLUGIN(QCocoaIntegrationPlugin)
 Q_IMPORT_PLUGIN(QGenericEnginePlugin)
-#elif defined Q_OS_LINUX // Q_OS_WIN | Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_WIN | Q_OS_MAC
 Q_IMPORT_PLUGIN(QXcbIntegrationPlugin)
 Q_IMPORT_PLUGIN(QGenericEnginePlugin)
 Q_IMPORT_PLUGIN(QComposePlatformInputContextPlugin)
@@ -33,4 +33,4 @@ Q_IMPORT_PLUGIN(QHimePlatformInputContextPlugin)
 Q_IMPORT_PLUGIN(NimfInputContextPlugin)
 Q_IMPORT_PLUGIN(QXdgDesktopPortalThemePlugin)
 #endif // !TDESKTOP_DISABLE_DBUS_INTEGRATION
-#endif // Q_OS_WIN | Q_OS_MAC | Q_OS_LINUX
+#endif // Q_OS_WIN | Q_OS_MAC | Q_OS_LINUX | Q_OS_FREEBSD
