--- Telegram/SourceFiles/qt_static_plugins.cpp.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/qt_static_plugins.cpp
@@ -27,14 +27,5 @@ Q_IMPORT_PLUGIN(QWindowsIntegrationPlugi
 Q_IMPORT_PLUGIN(QWebpPlugin)
 Q_IMPORT_PLUGIN(QCocoaIntegrationPlugin)
 Q_IMPORT_PLUGIN(QGenericEnginePlugin)
-#elif defined Q_OS_LINUX // Q_OS_WIN | Q_OS_MAC
-Q_IMPORT_PLUGIN(QWebpPlugin)
-Q_IMPORT_PLUGIN(QXcbIntegrationPlugin)
-Q_IMPORT_PLUGIN(QConnmanEnginePlugin)
-Q_IMPORT_PLUGIN(QGenericEnginePlugin)
-Q_IMPORT_PLUGIN(QNetworkManagerEnginePlugin)
-Q_IMPORT_PLUGIN(QComposePlatformInputContextPlugin)
-Q_IMPORT_PLUGIN(QIbusPlatformInputContextPlugin)
-Q_IMPORT_PLUGIN(QFcitxPlatformInputContextPlugin)
-Q_IMPORT_PLUGIN(QHimePlatformInputContextPlugin)
-#endif // Q_OS_WIN | Q_OS_MAC | Q_OS_LINUX
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_WIN | Q_OS_MAC
+#endif // Q_OS_WIN | Q_OS_MAC | Q_OS_LINUX | Q_OS_FREEBSD
