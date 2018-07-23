--- base/process/process_handle.h.orig	2018-07-19 22:31:39.988330000 +0200
+++ base/process/process_handle.h	2018-07-19 22:32:06.977544000 +0200
@@ -64,7 +64,7 @@
 // a process's PID.
 BASE_EXPORT uint32_t GetUniqueIdForProcess();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // When a process is started in a different PID namespace from the browser
 // process, this function must be called with the process's PID in the browser's
 // PID namespace in order to initialize its unique ID. Not thread safe.
