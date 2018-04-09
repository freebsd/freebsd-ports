--- src/modes/system/systemConfiguration.h.orig	2015-11-20 20:21:44 UTC
+++ src/modes/system/systemConfiguration.h
@@ -38,7 +38,7 @@ class SystemConfiguration : public Gener
 public:
     SystemConfiguration()
         : GenericLogModeConfiguration(QStringLiteral(SYSTEM_LOG_MODE_ID),
-                                      QStringList() << QStringLiteral("/var/log/syslog"),
+                                      QStringList() << QStringLiteral("/var/log/messages"),
                                       QList<int>() << Globals::INFORMATION_LOG_LEVEL_ID)
     {
         /*
