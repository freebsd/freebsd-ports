--- Telegram/SourceFiles/logs.cpp.orig	2018-02-06 05:51:11 UTC
+++ Telegram/SourceFiles/logs.cpp
@@ -321,7 +321,7 @@ void start(not_null<Core::Launcher*> lau
 	if (cBetaVersion()) {
 		cSetDebug(true);
 		workingDirChosen = true;
-#if defined Q_OS_MAC || defined Q_OS_LINUX
+#if defined Q_OS_MAC || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 	} else {
 #ifdef _DEBUG
 		cForceWorkingDir(cExeDir());
@@ -335,15 +335,15 @@ void start(not_null<Core::Launcher*> lau
 #endif // !_DEBUG
 		workingDirChosen = true;
 
-#if defined Q_OS_LINUX && !defined _DEBUG // fix first version
+#if (defined Q_OS_LINUX || defined Q_OS_FREEBSD) && !defined _DEBUG // fix first version
 		moveOldDataFrom = initialWorkingDir;
 #endif // Q_OS_LINUX && !_DEBUG
 
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
@@ -357,7 +357,7 @@ void start(not_null<Core::Launcher*> lau
 			cForceWorkingDir(cWorkingDir());
 			workingDirChosen = true;
 		}
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || OS_WIN_STORE
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || OS_WIN_STORE || Q_OS_FREEBSD
 	}
 
 	LogsData = new LogsDataFields();
