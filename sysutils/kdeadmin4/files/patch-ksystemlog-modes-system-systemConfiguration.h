--- ksystemlog/src/modes/system/systemConfiguration.h.o	2009-06-09 12:38:16.000000000 -0400
+++ ksystemlog/src/modes/system/systemConfiguration.h	2009-06-09 12:38:27.000000000 -0400
@@ -39,7 +39,7 @@
 		SystemConfiguration() :
 			GenericLogModeConfiguration(
 					SYSTEM_LOG_MODE_ID, 
-					QStringList() << "/var/log/syslog",
+					QStringList() << "/var/log/messages",
 					QList<int>() << INFORMATION_LOG_LEVEL_ID
 			) {
 			
