--- media/capture/video/mock_gpu_memory_buffer_manager.cc.orig	2019-03-11 22:00:59 UTC
+++ media/capture/video/mock_gpu_memory_buffer_manager.cc
@@ -103,7 +103,7 @@ class FakeGpuMemoryBuffer : public gfx::GpuMemoryBuffe
     gfx::GpuMemoryBufferHandle handle;
     handle.type = gfx::NATIVE_PIXMAP;
     handle.id = handle_.id;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     handle.native_pixmap_handle =
         gfx::CloneHandleForIPC(handle_.native_pixmap_handle);
 #endif
