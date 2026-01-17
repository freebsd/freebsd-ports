--- chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc.orig	2026-01-16 14:21:21 UTC
+++ chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc
@@ -332,7 +332,7 @@ void BrowserViewAppLayoutImpl::DoPostLayoutVisualAdjus
     label.SetSubpixelRenderingEnabled(false);
     label.SetHorizontalAlignment(gfx::ALIGN_LEFT);
     label.SetAutoColorReadabilityEnabled(false);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     label.SetSubpixelRenderingEnabled(false);
     label.SetHorizontalAlignment(gfx::ALIGN_LEFT);
 #endif
