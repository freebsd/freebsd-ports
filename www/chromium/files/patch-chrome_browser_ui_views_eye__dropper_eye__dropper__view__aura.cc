--- chrome/browser/ui/views/eye_dropper/eye_dropper_view_aura.cc.orig	2021-12-14 11:44:59 UTC
+++ chrome/browser/ui/views/eye_dropper/eye_dropper_view_aura.cc
@@ -80,7 +80,7 @@ void EyeDropperView::MoveViewToFront() {
 }
 
 void EyeDropperView::CaptureInputIfNeeded() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // The eye dropper needs to capture input since it is not activated
   // in order to avoid dismissing the color picker.
   GetWidget()->GetNativeWindow()->SetCapture();
