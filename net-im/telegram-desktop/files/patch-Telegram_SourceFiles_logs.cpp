--- Telegram/SourceFiles/logs.cpp.orig	2019-02-01 12:51:46 UTC
+++ Telegram/SourceFiles/logs.cpp
@@ -333,7 +333,7 @@ void start(not_null<Core::Launcher*> launcher) {
 	if (cAlphaVersion()) {
 		workingDirChosen = true;
 
-#if defined Q_OS_MAC || defined Q_OS_LINUX
+#if defined Q_OS_MAC || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 	} else {
 		if (!cWorkingDir().isEmpty()) {
 			// This value must come from TelegramForcePortable
@@ -348,16 +348,16 @@ void start(not_null<Core::Launcher*> launcher) {
 		}
 		workingDirChosen = true;
 
-#if defined Q_OS_LINUX && !defined _DEBUG // fix first version
+#if (defined Q_OS_LINUX || defined Q_OS_FREEBSD) && !defined _DEBUG // fix first version
 		moveOldDataFrom = initialWorkingDir;
-#endif // Q_OS_LINUX && !_DEBUG
+#endif // (Q_OS_LINUX || Q_OS_FREEBSD) && !_DEBUG
 
-#elif defined Q_OS_WINRT // Q_OS_MAC || Q_OS_LINUX
+#elif defined Q_OS_WINRT // Q_OS_MAC || Q_OS_LINUX || Q_OS_FREEBSD
 	} else {
 		cForceWorkingDir(psAppDataPath());
 		workingDirChosen = true;
 
-#elif defined OS_WIN_STORE // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT
+#elif defined OS_WIN_STORE // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || Q_OS_FREEBSD
 #ifdef _DEBUG
 		cForceWorkingDir(cExeDir());
 #else // _DEBUG
@@ -374,7 +374,7 @@ void start(not_null<Core::Launcher*> launcher) {
 			workingDirChosen = true;
 		}
 
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || OS_WIN_STORE
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || OS_WIN_STORE || Q_OS_FREEBSD
 	}
 
 	LogsData = new LogsDataFields();
