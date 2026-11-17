--- src/chrome/browser/ui/views/frame/opaque_browser_frame_view_layout_delegate.h.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/views/frame/opaque_browser_frame_view_layout_delegate.h
@@ -9,7 +9,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ui_base_types.h"
 #endif
 
@@ -83,7 +83,7 @@ class OpaqueBrowserFrameViewLayoutDelega
   // Returns true if a client-side shadow should be drawn for restored windows.
   virtual bool ShouldDrawRestoredFrameShadow() const = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the window is in a tiled state.
   virtual bool IsTiled() const = 0;
 #endif
