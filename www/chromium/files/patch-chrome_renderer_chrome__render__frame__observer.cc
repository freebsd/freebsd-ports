--- chrome/renderer/chrome_render_frame_observer.cc.orig	2021-09-24 18:38:51 UTC
+++ chrome/renderer/chrome_render_frame_observer.cc
@@ -281,7 +281,7 @@ void ChromeRenderFrameObserver::OnDestruct() {
 }
 
 void ChromeRenderFrameObserver::DraggableRegionsChanged() {
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
   // Only the main frame is allowed to control draggable regions, to avoid other
   // frames manipulate the regions in the browser process.
   if (!render_frame()->IsMainFrame())
