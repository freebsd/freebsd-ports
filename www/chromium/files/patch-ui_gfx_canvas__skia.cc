--- ui/gfx/canvas_skia.cc.orig	2017-04-19 19:06:54 UTC
+++ ui/gfx/canvas_skia.cc
@@ -201,7 +201,7 @@ void Canvas::DrawStringRectWithFlags(con
     Range range = StripAcceleratorChars(flags, &adjusted_text);
     bool elide_text = ((flags & NO_ELLIPSIS) == 0);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // On Linux, eliding really means fading the end of the string. But only
     // for LTR text. RTL text is still elided (on the left) with "...".
     if (elide_text) {
