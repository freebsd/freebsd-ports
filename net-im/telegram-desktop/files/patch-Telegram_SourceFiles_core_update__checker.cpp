--- Telegram/SourceFiles/core/update_checker.cpp.orig	2019-10-07 15:58:21 UTC
+++ Telegram/SourceFiles/core/update_checker.cpp
@@ -1459,6 +1459,9 @@ int UpdateChecker::size() const {
 //}
 
 bool checkReadyUpdate() {
+#ifdef Q_OS_FREEBSD
+    return false;
+#endif
 	QString readyFilePath = cWorkingDir() + qsl("tupdates/temp/ready"), readyPath = cWorkingDir() + qsl("tupdates/temp");
 	if (!QFile(readyFilePath).exists() || cExeName().isEmpty()) {
 		if (QDir(cWorkingDir() + qsl("tupdates/ready")).exists() || QDir(cWorkingDir() + qsl("tupdates/temp")).exists()) {
@@ -1511,6 +1514,9 @@ bool checkReadyUpdate() {
 #elif defined Q_OS_LINUX // Q_OS_MAC
 	QString curUpdater = (cExeDir() + qsl("Updater"));
 	QFileInfo updater(cWorkingDir() + qsl("tupdates/temp/Updater"));
+#elif defined Q_OS_FREEBSD
+	QString curUpdater;
+	QFileInfo updater;
 #endif // Q_OS_LINUX
 	if (!updater.exists()) {
 		QFileInfo current(curUpdater);
