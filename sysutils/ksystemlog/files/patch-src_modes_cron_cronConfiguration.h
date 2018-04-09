--- src/modes/cron/cronConfiguration.h.orig	2015-11-20 21:21:48 UTC
+++ src/modes/cron/cronConfiguration.h
@@ -52,7 +52,7 @@ public:
         configuration->setCurrentGroup(QStringLiteral("CronLogMode"));
 
         QStringList defaultCronPaths;
-        defaultCronPaths << QStringLiteral("/var/log/syslog");
+        defaultCronPaths << QStringLiteral("/var/log/cron");
         configuration->addItemStringList(QStringLiteral("LogFilesPaths"), d->cronPaths, defaultCronPaths,
                                          QStringLiteral("LogFilesPaths"));
 
