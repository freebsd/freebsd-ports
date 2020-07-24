--- media/video/fake_gpu_memory_buffer.cc.orig	2019-12-17 19:43:52 UTC
+++ media/video/fake_gpu_memory_buffer.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -44,7 +44,7 @@ class FakeGpuMemoryBufferImpl : public gpu::GpuMemoryB
 
 }  // namespace
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 base::ScopedFD GetDummyFD() {
   base::ScopedFD fd(open("/dev/zero", O_RDWR));
   DCHECK(fd.is_valid());
@@ -67,7 +67,7 @@ FakeGpuMemoryBuffer::FakeGpuMemoryBuffer(const gfx::Si
   // Set a dummy id since this is for testing only.
   handle_.id = gfx::GpuMemoryBufferId(0);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Set a dummy fd since this is for testing only.
   handle_.native_pixmap_handle.planes.push_back(
       gfx::NativePixmapPlane(size_.width(), 0, y_plane_size, GetDummyFD()));
@@ -76,7 +76,7 @@ FakeGpuMemoryBuffer::FakeGpuMemoryBuffer(const gfx::Si
         size_.width(), handle_.native_pixmap_handle.planes[0].size,
         uv_plane_size, GetDummyFD()));
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 FakeGpuMemoryBuffer::~FakeGpuMemoryBuffer() = default;
@@ -135,7 +135,7 @@ gfx::GpuMemoryBufferHandle FakeGpuMemoryBuffer::CloneH
   gfx::GpuMemoryBufferHandle handle;
   handle.type = gfx::NATIVE_PIXMAP;
   handle.id = handle_.id;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   handle.native_pixmap_handle =
       gfx::CloneHandleForIPC(handle_.native_pixmap_handle);
 #endif
