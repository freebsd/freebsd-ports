--- chrome/renderer/chrome_render_frame_observer.cc.orig	2024-03-22 14:16:19 UTC
+++ chrome/renderer/chrome_render_frame_observer.cc
@@ -353,7 +353,7 @@ void ChromeRenderFrameObserver::WillDetach(blink::Deta
 
 void ChromeRenderFrameObserver::DraggableRegionsChanged() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Only the main frame is allowed to control draggable regions, to avoid other
   // frames manipulate the regions in the browser process.
   if (!render_frame()->IsMainFrame())
