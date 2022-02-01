--- chrome/browser/ui/views/frame/browser_view.cc.orig	2021-12-31 00:57:25 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -1766,7 +1766,7 @@ void BrowserView::TabDraggingStatusChanged(bool is_dra
   // CrOS cleanup is done.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   contents_web_view_->SetFastResize(is_dragging);
   if (!is_dragging) {
     // When tab dragging is ended, we need to make sure the web contents get
