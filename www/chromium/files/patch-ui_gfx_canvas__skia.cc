--- ui/gfx/canvas_skia.cc.orig	2022-02-07 13:39:41 UTC
+++ ui/gfx/canvas_skia.cc
@@ -209,7 +209,7 @@ void Canvas::DrawStringRectWithFlags(const std::u16str
     Range range = StripAcceleratorChars(flags, &adjusted_text);
     bool elide_text = ((flags & NO_ELLIPSIS) == 0);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // On Linux, eliding really means fading the end of the string. But only
     // for LTR text. RTL text is still elided (on the left) with "...".
     if (elide_text) {
