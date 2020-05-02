--- Telegram/SourceFiles/logs.cpp.orig	2020-02-18 08:28:06 UTC
+++ Telegram/SourceFiles/logs.cpp
@@ -342,7 +342,7 @@ void start(not_null<Core::Launcher*> launcher) {
 		workingDirChosen = true;
 	} else {
 
-#if defined Q_OS_MAC || defined Q_OS_LINUX
+#if defined Q_OS_MAC || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 
 		if (!cWorkingDir().isEmpty()) {
 			// This value must come from TelegramForcePortable
@@ -357,16 +357,16 @@ void start(not_null<Core::Launcher*> launcher) {
 		}
 		workingDirChosen = true;
 
-#if defined Q_OS_LINUX && !defined _DEBUG // fix first version
+#if (defined Q_OS_LINUX || defined Q_OS_FREEBSD) && !defined _DEBUG // fix first version
 		moveOldDataFrom = initialWorkingDir;
-#endif // Q_OS_LINUX && !_DEBUG
+#endif // (Q_OS_LINUX || Q_OS_FREEBSD) && !_DEBUG
 
-#elif defined Q_OS_WINRT // Q_OS_MAC || Q_OS_LINUX
+#elif defined Q_OS_WINRT // Q_OS_MAC || Q_OS_LINUX || Q_OS_FREEBSD
 
 		cForceWorkingDir(psAppDataPath());
 		workingDirChosen = true;
 
-#elif defined OS_WIN_STORE // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT
+#elif defined OS_WIN_STORE // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || Q_OS_FREEBSD
 
 #ifdef _DEBUG
 		cForceWorkingDir(cExeDir());
@@ -383,7 +383,7 @@ void start(not_null<Core::Launcher*> launcher) {
 			workingDirChosen = true;
 		}
 
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || OS_WIN_STORE
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || OS_WIN_STORE || Q_OS_FREEBSD
 
 	}
 
