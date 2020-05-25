--- Telegram/SourceFiles/qt_static_plugins.cpp.orig	2020-05-24 07:59:19 UTC
+++ Telegram/SourceFiles/qt_static_plugins.cpp
@@ -20,7 +20,7 @@ Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
 #elif defined Q_OS_MAC // Q_OS_WIN
 Q_IMPORT_PLUGIN(QCocoaIntegrationPlugin)
 Q_IMPORT_PLUGIN(QGenericEnginePlugin)
-#elif defined Q_OS_LINUX // Q_OS_WIN | Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_WIN | Q_OS_MAC
 Q_IMPORT_PLUGIN(ShmServerBufferPlugin)
 Q_IMPORT_PLUGIN(DmaBufServerBufferPlugin)
 Q_IMPORT_PLUGIN(DrmEglServerBufferPlugin)
@@ -44,10 +44,10 @@ Q_IMPORT_PLUGIN(QNetworkManagerEnginePlugin)
 Q_IMPORT_PLUGIN(QIbusPlatformInputContextPlugin)
 Q_IMPORT_PLUGIN(QXdgDesktopPortalThemePlugin)
 #endif // !TDESKTOP_DISABLE_DBUS_INTEGRATION
-#endif // Q_OS_WIN | Q_OS_MAC | Q_OS_LINUX
+#endif // Q_OS_WIN | Q_OS_MAC | Q_OS_LINUX | Q_OS_FREEBSD
 #endif // !DESKTOP_APP_USE_PACKAGED
 
-#ifdef Q_OS_LINUX
+#if defined Q_OS_LINUX || defined Q_OS_FREEBSD
 #if !defined DESKTOP_APP_USE_PACKAGED || defined DESKTOP_APP_USE_PACKAGED_LAZY
 Q_IMPORT_PLUGIN(QWaylandMaterialDecorationPlugin)
 Q_IMPORT_PLUGIN(NimfInputContextPlugin)
