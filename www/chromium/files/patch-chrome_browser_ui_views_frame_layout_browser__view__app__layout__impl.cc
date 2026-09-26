--- chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc
@@ -400,7 +400,7 @@ void BrowserViewAppLayoutImpl::DoPostLayoutVisualAdjus
 #elif BUILDFLAG(IS_WIN)
     label.SetSubpixelRenderingEnabled(false);
     label.SetAutoColorReadabilityEnabled(false);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     label.SetSubpixelRenderingEnabled(false);
 #endif
   }
