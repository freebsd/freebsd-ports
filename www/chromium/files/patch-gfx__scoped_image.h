--- gfx/scoped_image.h.orig	2011-03-20 22:02:04.269886673 +0200
+++ gfx/scoped_image.h	2011-03-20 22:02:04.438736904 +0200
@@ -11,7 +11,7 @@
 #include "gfx/native_widget_types.h"
 #include "third_party/skia/include/core/SkBitmap.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include <glib-object.h>
 #elif defined(OS_MACOSX)
 #include "base/mac/mac_util.h"
@@ -116,7 +116,7 @@
 #endif  // defined(OS_MACOSX)
 
 // Specialization for the GdkPixbuf type on Linux.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 template <>
 class ScopedImage<GdkPixbuf> : public gfx::internal::ScopedImage<GdkPixbuf> {
  public:
