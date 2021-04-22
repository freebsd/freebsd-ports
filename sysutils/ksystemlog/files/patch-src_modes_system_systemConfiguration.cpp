--- src/modes/system/systemConfiguration.cpp.orig	2021-04-09 06:15:17 UTC
+++ src/modes/system/systemConfiguration.cpp
@@ -23,7 +23,8 @@
 
 SystemConfiguration::SystemConfiguration()
     : GenericLogModeConfiguration(QStringLiteral(SYSTEM_LOG_MODE_ID),
-                                  QStringList() << QStringLiteral("/var/log/syslog"),
+                                  QStringList() << QStringLiteral("/var/log/syslog")
+				 		<< QStringLiteral("/var/log/messages"),
                                   QList<int>() << Globals::INFORMATION_LOG_LEVEL_ID)
 {
     /*
