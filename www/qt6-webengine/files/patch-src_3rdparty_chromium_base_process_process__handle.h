--- src/3rdparty/chromium/base/process/process_handle.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/process/process_handle.h
@@ -106,7 +106,7 @@ BASE_EXPORT UniqueProcId GetUniqueIdForProcess();
 // processes may be reused.
 BASE_EXPORT UniqueProcId GetUniqueIdForProcess();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // When a process is started in a different PID namespace from the browser
 // process, this function must be called with the process's PID in the browser's
 // PID namespace in order to initialize its unique ID. Not thread safe.
