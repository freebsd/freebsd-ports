--- chrome/browser/ui/views/frame/browser_widget.h.orig	2025-12-06 13:30:52 UTC
+++ chrome/browser/ui/views/frame/browser_widget.h
@@ -65,7 +65,7 @@ class BrowserWidget : public views::Widget,
 
   ~BrowserWidget() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the frame is in a tiled state.
   bool tiled() const { return tiled_; }
   void set_tiled(bool tiled) { tiled_ = tiled; }
@@ -187,7 +187,7 @@ class BrowserWidget : public views::Widget,
   // contents for smoother dragging.
   TabDragKind tab_drag_kind_ = TabDragKind::kNone;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool tiled_ = false;
 #endif
 };
