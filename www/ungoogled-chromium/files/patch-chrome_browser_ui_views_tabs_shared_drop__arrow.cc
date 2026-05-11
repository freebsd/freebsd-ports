--- chrome/browser/ui/views/tabs/shared/drop_arrow.cc.orig	2026-05-09 18:09:27 UTC
+++ chrome/browser/ui/views/tabs/shared/drop_arrow.cc
@@ -76,7 +76,7 @@ DropArrow::~DropArrow() {
 
 // static
 void DropArrow::MaybeAdjustDisplayBounds(gfx::Rect& display_bounds) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, `GetBoundsInScreen` returns coordinates relative to the browser
   // window (plus shadow elevation outsets) rather than the screen. To handle
   // this, we adjust the display bounds by the difference between the drop arrow
