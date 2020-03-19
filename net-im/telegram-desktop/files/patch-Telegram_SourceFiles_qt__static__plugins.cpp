--- Telegram/SourceFiles/qt_static_plugins.cpp.orig	2020-03-16 18:49:16 UTC
+++ Telegram/SourceFiles/qt_static_plugins.cpp
@@ -19,7 +19,7 @@ Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
 #elif defined Q_OS_MAC // Q_OS_WIN
 Q_IMPORT_PLUGIN(QCocoaIntegrationPlugin)
 Q_IMPORT_PLUGIN(QGenericEnginePlugin)
-#elif defined Q_OS_LINUX // Q_OS_WIN | Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_WIN | Q_OS_MAC
 Q_IMPORT_PLUGIN(ShmServerBufferPlugin)
 Q_IMPORT_PLUGIN(DmaBufServerBufferPlugin)
 Q_IMPORT_PLUGIN(DrmEglServerBufferPlugin)
@@ -45,4 +45,4 @@ Q_IMPORT_PLUGIN(QHimePlatformInputContextPlugin)
 Q_IMPORT_PLUGIN(NimfInputContextPlugin)
 Q_IMPORT_PLUGIN(QXdgDesktopPortalThemePlugin)
 #endif // !TDESKTOP_DISABLE_DBUS_INTEGRATION
-#endif // Q_OS_WIN | Q_OS_MAC | Q_OS_LINUX
+#endif // Q_OS_WIN | Q_OS_MAC | Q_OS_LINUX | Q_OS_FREEBSD
