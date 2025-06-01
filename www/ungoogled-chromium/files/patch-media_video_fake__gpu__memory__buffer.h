--- media/video/fake_gpu_memory_buffer.h.orig	2025-05-31 17:16:41 UTC
+++ media/video/fake_gpu_memory_buffer.h
@@ -12,7 +12,7 @@
 
 namespace media {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // This method is used by tests to create a fake pixmap handle instead of
 // creating a FakeGpuMemoryBuffer. Once all tests are converted to use it,
 // FakeGpuMemoryBuffer will be removed and this file will be renamed
