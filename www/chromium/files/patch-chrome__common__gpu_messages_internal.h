--- chrome/common/gpu_messages_internal.h.orig	2011-04-15 11:02:02.000000000 +0300
+++ chrome/common/gpu_messages_internal.h	2011-04-16 19:43:55.218070312 +0300
@@ -142,7 +142,7 @@
 // Response from GPU to a GpuMsg_Synchronize message.
 IPC_MESSAGE_CONTROL0(GpuHostMsg_SynchronizeReply)
 
-#if defined(OS_LINUX) && !defined(TOUCH_UI)
+#if (defined(OS_LINUX) || defined (OS_FREEBSD)) && !defined(TOUCH_UI)
 // Resize the window that is being drawn into. It's important that this
 // resize be synchronized with the swapping of the front and back buffers.
 IPC_SYNC_MESSAGE_CONTROL2_1(GpuHostMsg_ResizeXID,
