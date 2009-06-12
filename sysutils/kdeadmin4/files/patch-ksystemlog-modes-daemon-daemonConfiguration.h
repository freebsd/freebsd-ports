--- ksystemlog/src/modes/daemon/daemonConfiguration.h.o	2009-06-09 12:39:54.000000000 -0400
+++ ksystemlog/src/modes/daemon/daemonConfiguration.h	2009-06-09 12:40:06.000000000 -0400
@@ -47,7 +47,7 @@
 			configuration->setCurrentGroup("DaemonLogMode");
 			
 			QStringList defaultDaemonPaths;
-			defaultDaemonPaths << "/var/log/daemon.log";
+			defaultDaemonPaths << "/var/log/messages";
 			configuration->addItemStringList("LogFilesPaths", d->daemonPaths, defaultDaemonPaths, "LogFilesPaths");
 				
 		}
