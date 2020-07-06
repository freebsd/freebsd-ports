--- src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.cc.orig	2020-03-16 14:04:24 UTC
+++ src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.cc
@@ -28,7 +28,7 @@ GpuMemoryBufferHandle GpuMemoryBufferHandle::Clone() c
   handle.region = region.Duplicate();
   handle.offset = offset;
   handle.stride = stride;
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   handle.native_pixmap_handle = CloneHandleForIPC(native_pixmap_handle);
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
   NOTIMPLEMENTED();
