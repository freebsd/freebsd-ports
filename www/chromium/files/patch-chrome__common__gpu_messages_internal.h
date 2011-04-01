--- ./chrome/common/gpu_messages_internal.h.orig	2010-12-16 02:12:13.000000000 +0100
+++ ./chrome/common/gpu_messages_internal.h	2010-12-20 20:15:08.000000000 +0100
@@ -82,7 +82,7 @@
 IPC_MESSAGE_CONTROL1(GpuHostMsg_GraphicsInfoCollected,
                      GPUInfo /* GPU logging stats */)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Get the XID for a view ID.
 IPC_SYNC_MESSAGE_CONTROL1_1(GpuHostMsg_GetViewXID,
                             gfx::NativeViewId, /* view */
