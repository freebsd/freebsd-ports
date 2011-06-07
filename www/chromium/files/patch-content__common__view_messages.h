--- content/common/view_messages.h.orig	2011-06-05 19:01:24.752163332 +0300
+++ content/common/view_messages.h	2011-06-05 19:01:40.420163036 +0300
@@ -1783,7 +1783,7 @@
 IPC_MESSAGE_CONTROL1(ViewHostMsg_SuddenTerminationChanged,
                      bool /* enabled */)
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 // On OSX, we cannot allocated shared memory from within the sandbox, so
 // this call exists for the renderer to ask the browser to allocate memory
 // on its behalf. We return a file descriptor to the POSIX shared memory.
