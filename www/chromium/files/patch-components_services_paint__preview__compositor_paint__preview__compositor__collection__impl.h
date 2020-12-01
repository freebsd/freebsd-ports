--- components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.h.orig	2020-11-13 06:36:41 UTC
+++ components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.h
@@ -20,7 +20,7 @@
 #include "mojo/public/cpp/bindings/pending_receiver.h"
 #include "mojo/public/cpp/bindings/receiver.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #include "third_party/skia/include/core/SkRefCnt.h"
 #endif
@@ -74,7 +74,7 @@ class PaintPreviewCompositorCollectionImpl
                  std::unique_ptr<PaintPreviewCompositorImpl>>
       compositors_;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
