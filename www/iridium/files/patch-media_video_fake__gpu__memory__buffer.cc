--- media/video/fake_gpu_memory_buffer.cc.orig	2025-05-07 06:48:23 UTC
+++ media/video/fake_gpu_memory_buffer.cc
@@ -14,7 +14,7 @@
 #include "media/base/format_utils.h"
 #include "media/base/video_frame.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -29,7 +29,7 @@ namespace media {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 base::ScopedFD GetDummyFD() {
   base::ScopedFD fd(open("/dev/zero", O_RDWR));
   DCHECK(fd.is_valid());
@@ -73,7 +73,7 @@ static base::AtomicSequenceNumber buffer_id_generator;
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 gfx::GpuMemoryBufferHandle CreatePixmapHandleForTesting(
     const gfx::Size& size,
     gfx::BufferFormat format,
