--- chrome/gpu/gpu_channel.cc.orig	2011-01-26 10:30:52.000000000 +0100
+++ chrome/gpu/gpu_channel.cc	2011-01-30 14:12:45.000000000 +0100
@@ -139,7 +139,7 @@
   // offscreen rendering and the browser provides whichever platform specific
   // "render target" the GpuCommandBufferStub targets.
   handle = gfx::NativeViewFromId(view_id);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   // Ask the browser for the view's XID.
   gpu_thread_->Send(new GpuHostMsg_GetViewXID(view_id, &handle));
 #elif defined(OS_MACOSX)
