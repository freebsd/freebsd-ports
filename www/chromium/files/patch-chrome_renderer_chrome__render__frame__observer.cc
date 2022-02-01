--- chrome/renderer/chrome_render_frame_observer.cc.orig	2021-12-31 00:57:26 UTC
+++ chrome/renderer/chrome_render_frame_observer.cc
@@ -280,7 +280,7 @@ void ChromeRenderFrameObserver::OnDestruct() {
 }
 
 void ChromeRenderFrameObserver::DraggableRegionsChanged() {
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   // Only the main frame is allowed to control draggable regions, to avoid other
   // frames manipulate the regions in the browser process.
