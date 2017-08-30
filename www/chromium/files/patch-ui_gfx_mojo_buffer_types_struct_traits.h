--- ui/gfx/mojo/buffer_types_struct_traits.h.orig	2017-08-02 17:14:09.584825000 +0200
+++ ui/gfx/mojo/buffer_types_struct_traits.h	2017-08-02 17:14:27.990894000 +0200
@@ -240,7 +240,7 @@
                               void* context);
 
   static bool IsNull(const gfx::NativePixmapHandle& handle) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     return false;
 #else
     // NativePixmapHandle are not used on non-linux platforms.
