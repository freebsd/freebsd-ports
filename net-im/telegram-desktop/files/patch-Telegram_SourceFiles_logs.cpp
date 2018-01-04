--- Telegram/SourceFiles/logs.cpp.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/logs.cpp
@@ -311,7 +311,7 @@ namespace Logs {
 		QString initialWorkingDir = QDir(cWorkingDir()).absolutePath() + '/', moveOldDataFrom;
 		if (cBetaVersion()) {
 			cSetDebug(true);
-#if defined Q_OS_MAC || defined Q_OS_LINUX
+#if defined Q_OS_MAC || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 		} else {
 #ifdef _DEBUG
 			cForceWorkingDir(cExeDir());
@@ -322,11 +322,11 @@ namespace Logs {
 #endif // else for _DEBUG
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
@@ -502,7 +502,7 @@ namespace Logs {
 		//OutputDebugString(reinterpret_cast<const wchar_t *>(msg.utf16()));
 #elif defined Q_OS_MAC
 		//objc_outputDebugString(msg);
-#elif defined Q_OS_LINUX && defined _DEBUG
+#elif (defined Q_OS_LINUX || defined Q_OS_FREEBSD) && defined _DEBUG
 		//std::cout << msg.toUtf8().constData();
 #endif
 	}
