--- src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.cc
@@ -34,7 +34,7 @@ GpuMemoryBufferHandle GpuMemoryBufferHandle::Clone() c
   handle.region = region.Duplicate();
   handle.offset = offset;
   handle.stride = stride;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   handle.native_pixmap_handle = CloneHandleForIPC(native_pixmap_handle);
 #elif defined(OS_MAC)
   handle.mach_port = mach_port;
