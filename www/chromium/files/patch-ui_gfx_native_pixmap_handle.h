--- ui/gfx/native_pixmap_handle.h.orig	2017-08-02 17:17:40.381296000 +0200
+++ ui/gfx/native_pixmap_handle.h	2017-08-02 17:18:15.306967000 +0200
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "ui/gfx/gfx_export.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/file_descriptor_posix.h"
 #endif
 
@@ -46,14 +46,14 @@
 
   ~NativePixmapHandle();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // File descriptors for the underlying memory objects (usually dmabufs).
   std::vector<base::FileDescriptor> fds;
 #endif
   std::vector<NativePixmapPlane> planes;
 };
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Returns an instance of |handle| which can be sent over IPC. This duplicates
 // the file-handles, so that the IPC code take ownership of them, without
 // invalidating |handle|.
