diff --git ipc/glue/GeckoChildProcessHost.cpp ipc/glue/GeckoChildProcessHost.cpp
index 9bb8314bd98c..2bc0382a9385 100644
--- ipc/glue/GeckoChildProcessHost.cpp
+++ ipc/glue/GeckoChildProcessHost.cpp
@@ -1121,7 +1121,7 @@ Result<Ok, LaunchError> BaseProcessLauncher::DoSetup() {
 #if defined(MOZ_WIDGET_COCOA) || defined(XP_WIN)
     geckoargs::sCrashReporter.Put(CrashReporter::GetChildNotificationPipe(),
                                   mChildArgs);
-#elif defined(XP_UNIX) && !defined(XP_IOS)
+#elif defined(XP_UNIX) && !defined(XP_IOS) && !defined(XP_FREEBSD)
     UniqueFileHandle childCrashFd = CrashReporter::GetChildNotificationPipe();
     if (!childCrashFd) {
       return Err(LaunchError("DuplicateFileHandle failed"));
