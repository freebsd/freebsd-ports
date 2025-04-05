--- media/video/fake_gpu_memory_buffer.cc.orig	2025-04-04 08:52:13 UTC
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
@@ -84,7 +84,7 @@ gfx::GpuMemoryBufferHandle CreatePixmapHandleForTestin
   static base::AtomicSequenceNumber buffer_id_generator;
   handle.id = gfx::GpuMemoryBufferId(buffer_id_generator.GetNext());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   for (size_t i = 0; i < VideoFrame::NumPlanes(*video_pixel_format); i++) {
     const gfx::Size plane_size_in_bytes =
         VideoFrame::PlaneSize(*video_pixel_format, i, size);
@@ -187,7 +187,7 @@ gfx::GpuMemoryBufferHandle FakeGpuMemoryBuffer::CloneH
   gfx::GpuMemoryBufferHandle handle;
   handle.type = gfx::NATIVE_PIXMAP;
   handle.id = handle_.id;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   handle.native_pixmap_handle =
       gfx::CloneHandleForIPC(handle_.native_pixmap_handle);
 #endif
