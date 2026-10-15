--- chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc.orig	2026-04-09 06:05:42 UTC
+++ chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc
@@ -404,7 +404,7 @@ void BrowserViewAppLayoutImpl::DoPostLayoutVisualAdjus
 #elif BUILDFLAG(IS_WIN)
     label.SetSubpixelRenderingEnabled(false);
     label.SetAutoColorReadabilityEnabled(false);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     label.SetSubpixelRenderingEnabled(false);
 #endif
   }
