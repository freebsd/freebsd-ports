--- src/chrome/browser/ui/views/frame/browser_widget.h.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/views/frame/browser_widget.h
@@ -65,7 +65,7 @@ class BrowserWidget : public views::Widg
 
   ~BrowserWidget() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the frame is in a tiled state.
   bool tiled() const { return tiled_; }
   void set_tiled(bool tiled) { tiled_ = tiled; }
@@ -199,7 +199,7 @@ class BrowserWidget : public views::Widg
   // contents for smoother dragging.
   TabDragKind tab_drag_kind_ = TabDragKind::kNone;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool tiled_ = false;
 #endif
 };
