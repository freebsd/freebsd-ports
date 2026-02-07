--- src/modes/cron/cronConfiguration.cpp.orig	2021-04-12 19:57:29 UTC
+++ src/modes/cron/cronConfiguration.cpp
@@ -25,7 +25,7 @@ CronConfiguration::CronConfiguration()
 {
     mConfiguration->setCurrentGroup(QStringLiteral("CronLogMode"));
 
-    const QStringList defaultCronPaths{QStringLiteral("/var/log/syslog")};
+    const QStringList defaultCronPaths{QStringLiteral("/var/log/syslog"), QStringLiteral("/var/log/cron")};
     mConfiguration->addItemStringList(QStringLiteral("LogFilesPaths"), mCronPaths, defaultCronPaths, QStringLiteral("LogFilesPaths"));
 
     const QString defaultProcessFilter(QStringLiteral("/usr/sbin/cron"));
