--- media/video/fake_gpu_memory_buffer.cc.orig	2020-09-08 19:14:07 UTC
+++ media/video/fake_gpu_memory_buffer.cc
@@ -10,7 +10,7 @@
 #include "media/base/format_utils.h"
 #include "media/base/video_frame.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -48,7 +48,7 @@ class FakeGpuMemoryBufferImpl : public gpu::GpuMemoryB
 
 }  // namespace
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 base::ScopedFD GetDummyFD() {
   base::ScopedFD fd(open("/dev/zero", O_RDWR));
   DCHECK(fd.is_valid());
@@ -73,7 +73,7 @@ FakeGpuMemoryBuffer::FakeGpuMemoryBuffer(const gfx::Si
   static base::NoDestructor<base::AtomicSequenceNumber> buffer_id_generator;
   handle_.id = gfx::GpuMemoryBufferId(buffer_id_generator->GetNext());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   for (size_t i = 0; i < VideoFrame::NumPlanes(video_pixel_format_); i++) {
     const gfx::Size plane_size_in_bytes =
         VideoFrame::PlaneSize(video_pixel_format_, i, size_);
@@ -81,7 +81,7 @@ FakeGpuMemoryBuffer::FakeGpuMemoryBuffer(const gfx::Si
         plane_size_in_bytes.width(), 0, plane_size_in_bytes.GetArea(),
         GetDummyFD());
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 FakeGpuMemoryBuffer::~FakeGpuMemoryBuffer() = default;
@@ -129,7 +129,7 @@ gfx::GpuMemoryBufferHandle FakeGpuMemoryBuffer::CloneH
   gfx::GpuMemoryBufferHandle handle;
   handle.type = gfx::NATIVE_PIXMAP;
   handle.id = handle_.id;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   handle.native_pixmap_handle =
       gfx::CloneHandleForIPC(handle_.native_pixmap_handle);
 #endif
