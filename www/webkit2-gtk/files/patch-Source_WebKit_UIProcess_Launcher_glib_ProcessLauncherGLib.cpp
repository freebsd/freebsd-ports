--- Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp.orig	2024-09-30 08:15:01 UTC
+++ Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp
@@ -160,7 +160,11 @@ void ProcessLauncher::launchProcess()
     }
 
     realExecutablePath = FileSystem::fileSystemRepresentation(executablePath);
+#if OS(LINUX)
     unsigned nargs = 5; // size of the argv array for g_spawn_async()
+#else
+    unsigned nargs = 4; // size of the argv array for g_spawn_async()
+#endif
 
 #if ENABLE(DEVELOPER_MODE)
     Vector<CString> prefixArgs;
@@ -187,7 +191,9 @@ void ProcessLauncher::launchProcess()
     argv[i++] = const_cast<char*>(realExecutablePath.data());
     argv[i++] = processIdentifier.get();
     argv[i++] = webkitSocket.get();
+#if OS(LINUX)
     argv[i++] = pidSocketString.get();
+#endif
 #if ENABLE(DEVELOPER_MODE)
     if (configureJSCForTesting)
         argv[i++] = const_cast<char*>("--configure-jsc-for-testing");
