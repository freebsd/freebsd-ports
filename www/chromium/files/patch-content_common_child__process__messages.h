--- content/common/child_process_messages.h.orig	2017-06-05 19:03:07 UTC
+++ content/common/child_process_messages.h
@@ -26,7 +26,7 @@
 #include "ui/gfx/ipc/gfx_param_traits.h"
 #include "ui/gfx/ipc/skia/gfx_skia_param_traits.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/threading/platform_thread.h"
 #endif
 
@@ -75,7 +75,7 @@ IPC_STRUCT_TRAITS_BEGIN(tracked_objects::ProcessDataSn
   IPC_STRUCT_TRAITS_MEMBER(process_id)
 IPC_STRUCT_TRAITS_END()
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 IPC_ENUM_TRAITS_MAX_VALUE(base::ThreadPriority,
                           base::ThreadPriority::REALTIME_AUDIO)
 #endif
@@ -171,7 +171,7 @@ IPC_SYNC_MESSAGE_CONTROL1_0(ChildProcessHostMsg_PreCac
 IPC_MESSAGE_CONTROL0(ChildProcessHostMsg_ReleaseCachedFonts)
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Asks the browser to change the priority of thread.
 IPC_MESSAGE_CONTROL2(ChildProcessHostMsg_SetThreadPriority,
                      base::PlatformThreadId,
