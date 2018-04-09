--- src/modes/daemon/daemonConfiguration.h.orig	2015-11-20 20:21:00 UTC
+++ src/modes/daemon/daemonConfiguration.h
@@ -48,7 +48,7 @@ public:
         configuration->setCurrentGroup(QStringLiteral("DaemonLogMode"));
 
         QStringList defaultDaemonPaths;
-        defaultDaemonPaths << QStringLiteral("/var/log/daemon.log");
+        defaultDaemonPaths << QStringLiteral("/var/log/messages");
         configuration->addItemStringList(QStringLiteral("LogFilesPaths"), d->daemonPaths, defaultDaemonPaths,
                                          QStringLiteral("LogFilesPaths"));
     }
