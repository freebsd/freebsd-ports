--- media/capture/video/mock_gpu_memory_buffer_manager.cc.orig	2019-01-09 13:03:04.440957000 +0100
+++ media/capture/video/mock_gpu_memory_buffer_manager.cc	2019-01-09 13:03:18.319442000 +0100
@@ -103,7 +103,7 @@
     gfx::GpuMemoryBufferHandle handle;
     handle.type = gfx::NATIVE_PIXMAP;
     handle.id = handle_.id;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     handle.native_pixmap_handle =
         gfx::CloneHandleForIPC(handle_.native_pixmap_handle);
 #endif
