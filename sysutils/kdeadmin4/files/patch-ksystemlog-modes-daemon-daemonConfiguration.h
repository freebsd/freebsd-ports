--- ksystemlog/src/modes/daemon/daemonConfiguration.h.o	2009-06-09 12:39:54.000000000 -0400
+++ ksystemlog/src/modes/daemon/daemonConfiguration.h	2009-06-09 12:40:06.000000000 -0400
@@ -47,7 +47,7 @@
 			configuration->setCurrentGroup(QLatin1String( "DaemonLogMode" ));
 
 			QStringList defaultDaemonPaths;
-			defaultDaemonPaths << QLatin1String( "/var/log/daemon.log" );
+			defaultDaemonPaths << QLatin1String( "/var/log/messages" );
 			configuration->addItemStringList(QLatin1String( "LogFilesPaths" ), d->daemonPaths, defaultDaemonPaths, QLatin1String( "LogFilesPaths" ));
 
 		}
