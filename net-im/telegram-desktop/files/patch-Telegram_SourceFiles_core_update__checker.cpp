--- Telegram/SourceFiles/core/update_checker.cpp.orig	2019-04-13 06:46:58 UTC
+++ Telegram/SourceFiles/core/update_checker.cpp
@@ -1456,6 +1456,9 @@ int UpdateChecker::size() const {
 //}
 
 bool checkReadyUpdate() {
+#ifdef Q_OS_FREEBSD
+    return false;
+#endif
 	QString readyFilePath = cWorkingDir() + qsl("tupdates/temp/ready"), readyPath = cWorkingDir() + qsl("tupdates/temp");
 	if (!QFile(readyFilePath).exists() || cExeName().isEmpty()) {
 		if (QDir(cWorkingDir() + qsl("tupdates/ready")).exists() || QDir(cWorkingDir() + qsl("tupdates/temp")).exists()) {
@@ -1508,6 +1511,9 @@ bool checkReadyUpdate() {
 #elif defined Q_OS_LINUX // Q_OS_MAC
 	QString curUpdater = (cExeDir() + qsl("Updater"));
 	QFileInfo updater(cWorkingDir() + qsl("tupdates/temp/Updater"));
+#elif defined Q_OS_FREEBSD
+	QString curUpdater;
+	QFileInfo updater;
 #endif // Q_OS_LINUX
 	if (!updater.exists()) {
 		QFileInfo current(curUpdater);
