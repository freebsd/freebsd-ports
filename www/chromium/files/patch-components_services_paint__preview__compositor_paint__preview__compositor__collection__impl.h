--- components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.h.orig	2021-07-19 18:45:14 UTC
+++ components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.h
@@ -21,7 +21,7 @@
 #include "mojo/public/cpp/bindings/pending_receiver.h"
 #include "mojo/public/cpp/bindings/receiver.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #include "third_party/skia/include/core/SkRefCnt.h"
 #endif
@@ -73,7 +73,7 @@ class PaintPreviewCompositorCollectionImpl
                  std::unique_ptr<PaintPreviewCompositorImpl>>
       compositors_;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
