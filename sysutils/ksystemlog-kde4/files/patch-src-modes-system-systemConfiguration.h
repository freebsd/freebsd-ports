--- src/modes/system/systemConfiguration.h.orig	2013-08-10 12:29:30.156327556 +0000
+++ src/modes/system/systemConfiguration.h	2013-08-10 12:30:04.811327221 +0000
@@ -39,7 +39,7 @@
 		SystemConfiguration() :
 			GenericLogModeConfiguration(
 					QLatin1String( SYSTEM_LOG_MODE_ID ),
-					QStringList() << QLatin1String( "/var/log/syslog" ),
+					QStringList() << QLatin1String( "/var/log/messages" ),
 					QList<int>() << INFORMATION_LOG_LEVEL_ID
 			) {
 
