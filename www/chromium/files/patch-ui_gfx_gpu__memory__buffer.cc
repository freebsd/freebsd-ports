--- ui/gfx/gpu_memory_buffer.cc.orig	2019-12-17 19:59:38 UTC
+++ ui/gfx/gpu_memory_buffer.cc
@@ -28,7 +28,7 @@ GpuMemoryBufferHandle GpuMemoryBufferHandle::Clone() c
   handle.region = region.Duplicate();
   handle.offset = offset;
   handle.stride = stride;
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   handle.native_pixmap_handle = CloneHandleForIPC(native_pixmap_handle);
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
   NOTIMPLEMENTED();
