--- content/common/child_process_messages.h.orig	2017-02-02 02:02:53 UTC
+++ content/common/child_process_messages.h
@@ -27,7 +27,7 @@
 #include "ui/gfx/ipc/gfx_param_traits.h"
 #include "ui/gfx/ipc/skia/gfx_skia_param_traits.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/threading/platform_thread.h"
 #endif
 
@@ -70,7 +70,7 @@ IPC_STRUCT_TRAITS_BEGIN(tracked_objects:
   IPC_STRUCT_TRAITS_MEMBER(process_id)
 IPC_STRUCT_TRAITS_END()
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 IPC_ENUM_TRAITS_MAX_VALUE(base::ThreadPriority,
                           base::ThreadPriority::REALTIME_AUDIO)
 #endif
@@ -218,7 +218,7 @@ IPC_SYNC_MESSAGE_CONTROL2_1(
 IPC_MESSAGE_CONTROL1(ChildProcessHostMsg_DeletedDiscardableSharedMemory,
                      discardable_memory::DiscardableSharedMemoryId)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Asks the browser to change the priority of thread.
 IPC_MESSAGE_CONTROL2(ChildProcessHostMsg_SetThreadPriority,
                      base::PlatformThreadId,
