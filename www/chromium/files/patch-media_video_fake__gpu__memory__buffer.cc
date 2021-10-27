--- media/video/fake_gpu_memory_buffer.cc.orig	2021-09-14 01:51:59 UTC
+++ media/video/fake_gpu_memory_buffer.cc
@@ -10,7 +10,7 @@
 #include "media/base/format_utils.h"
 #include "media/base/video_frame.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -48,7 +48,7 @@ class FakeGpuMemoryBufferImpl : public gpu::GpuMemoryB
 
 }  // namespace
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 base::ScopedFD GetDummyFD() {
   base::ScopedFD fd(open("/dev/zero", O_RDWR));
   DCHECK(fd.is_valid());
@@ -78,7 +78,7 @@ FakeGpuMemoryBuffer::FakeGpuMemoryBuffer(const gfx::Si
   static base::AtomicSequenceNumber buffer_id_generator;
   handle_.id = gfx::GpuMemoryBufferId(buffer_id_generator.GetNext());
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   for (size_t i = 0; i < VideoFrame::NumPlanes(video_pixel_format_); i++) {
     const gfx::Size plane_size_in_bytes =
         VideoFrame::PlaneSize(video_pixel_format_, i, size_);
@@ -87,7 +87,7 @@ FakeGpuMemoryBuffer::FakeGpuMemoryBuffer(const gfx::Si
         GetDummyFD());
   }
   handle_.native_pixmap_handle.modifier = modifier;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 }
 
 FakeGpuMemoryBuffer::~FakeGpuMemoryBuffer() = default;
@@ -135,7 +135,7 @@ gfx::GpuMemoryBufferHandle FakeGpuMemoryBuffer::CloneH
   gfx::GpuMemoryBufferHandle handle;
   handle.type = gfx::NATIVE_PIXMAP;
   handle.id = handle_.id;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   handle.native_pixmap_handle =
       gfx::CloneHandleForIPC(handle_.native_pixmap_handle);
 #endif
