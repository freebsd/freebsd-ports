--- Telegram/SourceFiles/logs.cpp.orig	2018-08-04 18:53:40 UTC
+++ Telegram/SourceFiles/logs.cpp
@@ -333,7 +333,7 @@ void start(not_null<Core::Launcher*> lau
 	if (cBetaVersion()) {
 		SetDebugEnabled(true);
 		workingDirChosen = true;
-#if defined Q_OS_MAC || defined Q_OS_LINUX
+#if defined Q_OS_MAC || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 	} else {
 #ifdef _DEBUG
 		cForceWorkingDir(cExeDir());
@@ -347,15 +347,15 @@ void start(not_null<Core::Launcher*> lau
 #endif // !_DEBUG
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
@@ -369,7 +369,7 @@ void start(not_null<Core::Launcher*> lau
 			cForceWorkingDir(cWorkingDir());
 			workingDirChosen = true;
 		}
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || OS_WIN_STORE
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || OS_WIN_STORE || Q_OS_FREEBSD
 	}
 
 	LogsData = new LogsDataFields();
