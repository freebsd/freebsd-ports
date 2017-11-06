--- ui/gfx/gpu_memory_buffer.cc.orig	2017-08-02 17:09:18.637721000 +0200
+++ ui/gfx/gpu_memory_buffer.cc	2017-08-02 17:09:34.476081000 +0200
@@ -37,7 +37,7 @@
       gfx::GpuMemoryBufferHandle handle;
       handle.type = gfx::NATIVE_PIXMAP;
       handle.id = source_handle.id;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       handle.native_pixmap_handle =
           gfx::CloneHandleForIPC(source_handle.native_pixmap_handle);
 #endif
