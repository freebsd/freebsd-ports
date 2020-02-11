--- daemon/backends/upower/backlighthelper.cpp.orig	2020-02-03 18:04:25 UTC
+++ daemon/backends/upower/backlighthelper.cpp
@@ -135,7 +135,7 @@ void BacklightHelper::initUsingSysctl()
      */
     QStringList types;
     types << QStringLiteral("lcd") << QStringLiteral("out") << QStringLiteral("crt") << QStringLiteral("tv") << QStringLiteral("ext");
-    Q_FOREACH (const QString &type, types) {
+    for (auto &type : types) {
         for (int i = 0; m_sysctlDevice.isEmpty(); i++) {
             QString device = QStringLiteral("%1%2").arg(type, QString::number(i));
             // We don't care about the value, we only want the sysctl to be there.
@@ -236,7 +236,7 @@ ActionReply BacklightHelper::setbrightness(const QVari
     int actual_level = -1;
     int d1 = 101;
     // Search for the nearest level.
-    Q_FOREACH (int level, m_sysctlBrightnessLevels) {
+    for (auto level : m_sysctlBrightnessLevels) {
         int d2 = qAbs(level - actual_brightness);
         /*
          * The list is sorted, so we break when it starts diverging. There may be repeated values,
