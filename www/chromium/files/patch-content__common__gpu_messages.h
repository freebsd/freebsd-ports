--- content/common/gpu_messages.h.orig	2011-05-06 12:02:55.000000000 +0300
+++ content/common/gpu_messages.h	2011-06-04 01:15:56.427405297 +0300
@@ -161,7 +161,7 @@
 // information.
 IPC_MESSAGE_CONTROL0(GpuMsg_CollectGraphicsInfo)
 
-#if defined(OS_LINUX) && !defined(TOUCH_UI) || defined(OS_WIN)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(TOUCH_UI) || defined(OS_WIN)
 // Tells the GPU process that the browser process has finished resizing the
 // view.
 IPC_MESSAGE_CONTROL2(GpuMsg_ResizeViewACK,
@@ -250,7 +250,7 @@
 // Response from GPU to a GpuMsg_Synchronize message.
 IPC_MESSAGE_CONTROL0(GpuHostMsg_SynchronizeReply)
 
-#if defined(OS_LINUX) && !defined(TOUCH_UI) || defined(OS_WIN)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(TOUCH_UI) || defined(OS_WIN)
 // Resize the window that is being drawn into. It's important that this
 // resize be synchronized with the swapping of the front and back buffers.
 IPC_MESSAGE_CONTROL4(GpuHostMsg_ResizeView,
