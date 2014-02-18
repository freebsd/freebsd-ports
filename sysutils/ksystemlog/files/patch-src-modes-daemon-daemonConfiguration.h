--- src/modes/daemon/daemonConfiguration.h.orig	2013-08-10 12:25:48.939329058 +0000
+++ src/modes/daemon/daemonConfiguration.h	2013-08-10 12:26:06.097330372 +0000
@@ -47,7 +47,7 @@
 			configuration->setCurrentGroup(QLatin1String( "DaemonLogMode" ));
 
 			QStringList defaultDaemonPaths;
-			defaultDaemonPaths << QLatin1String( "/var/log/daemon.log" );
+			defaultDaemonPaths << QLatin1String( "/var/log/messages" );
 			configuration->addItemStringList(QLatin1String( "LogFilesPaths" ), d->daemonPaths, defaultDaemonPaths, QLatin1String( "LogFilesPaths" ));
 
 		}
