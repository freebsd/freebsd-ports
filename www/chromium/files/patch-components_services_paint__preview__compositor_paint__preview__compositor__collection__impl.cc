--- components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.cc.orig	2021-12-14 11:45:04 UTC
+++ components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.cc
@@ -17,7 +17,7 @@
 
 #if defined(OS_WIN)
 #include "content/public/child/dwrite_font_proxy_init_win.h"
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #endif
 
@@ -51,7 +51,7 @@ PaintPreviewCompositorCollectionImpl::PaintPreviewComp
     // Initialize font access for Skia.
 #if defined(OS_WIN)
   content::InitializeDWriteFontProxy();
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   mojo::PendingRemote<font_service::mojom::FontService> font_service;
   content::UtilityThread::Get()->BindHostReceiver(
       font_service.InitWithNewPipeAndPassReceiver());
@@ -70,7 +70,7 @@ PaintPreviewCompositorCollectionImpl::PaintPreviewComp
   // encoding to PNG or we could provide our own codec implementations.
 
   // Sanity check that fonts are working.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // No WebSandbox is provided on Linux so the local fonts aren't accessible.
   // This is fine since since the subsetted fonts are provided in the SkPicture.
   // However, we still need to check that the SkFontMgr starts as it is used by
