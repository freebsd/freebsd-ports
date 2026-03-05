--- src/core/settings.cpp.orig	2025-03-23 11:56:15 UTC
+++ src/core/settings.cpp
@@ -20,6 +20,7 @@
 
 #include <QtCore/QCoreApplication>
 #include <QtCore/QDebug>
+#include <QtCore/QDir>
 #include <QtCore/QStandardPaths>
 #include <QtCore/QVariant>
 
@@ -34,8 +35,11 @@ static QString defaultStreamHost() {
     return DEFAULT_STREAM_HOST_LIST.join(STREAM_HOST_SEPARATOR);
 }
 
-static QString defaultTorrentShareFolder() {
-    return QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
+static QString writableFolder(QStandardPaths::StandardLocation loc) {
+    const auto path = QStandardPaths::writableLocation(loc);
+    const QDir dir(path);
+    if (!dir.exists()) dir.mkpath(".");
+    return path;
 }
 
 
@@ -90,7 +94,8 @@ Settings::Settings(QObject *parent) : AbstractSettings
     addDefaultSettingBool(REGISTRY_REMOVE_COMPLETED, false);
     addDefaultSettingBool(REGISTRY_REMOVE_CANCELED, false);
     addDefaultSettingBool(REGISTRY_REMOVE_PAUSED, false);
-    addDefaultSettingString(REGISTRY_DATABASE, QString("%0/queue.json").arg(qApp->applicationDirPath()));
+    addDefaultSettingString(REGISTRY_DATABASE, QString("%0/queue.json")
+      .arg(writableFolder(QStandardPaths::AppDataLocation)));
     addDefaultSettingString(REGISTRY_HTTP_USER_AGENT, httpUserAgents().at(0));
     addDefaultSettingBool(REGISTRY_HTTP_REFERRER_ON, false);
     addDefaultSettingString(REGISTRY_HTTP_REFERRER, QLatin1String("https://www.example.com/"));
@@ -140,7 +145,7 @@ Settings::Settings(QObject *parent) : AbstractSettings
     // Tab Torrent
     addDefaultSettingBool(REGISTRY_TORRENT_ENABLED, true);
     addDefaultSettingBool(REGISTRY_TORRENT_SHARED, false);
-    addDefaultSettingString(REGISTRY_TORRENT_DIR, defaultTorrentShareFolder());
+    addDefaultSettingString(REGISTRY_TORRENT_DIR, writableFolder(QStandardPaths::DownloadLocation));
     addDefaultSettingString(REGISTRY_TORRENT_PEERS, QLatin1String(""));
     addDefaultSettingString(REGISTRY_TORRENT_ADVANCED, QLatin1String(""));
 
