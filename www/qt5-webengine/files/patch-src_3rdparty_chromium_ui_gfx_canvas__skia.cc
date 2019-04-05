--- src/3rdparty/chromium/ui/gfx/canvas_skia.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/gfx/canvas_skia.cc
@@ -208,7 +208,7 @@ void Canvas::DrawStringRectWithFlags(const base::strin
     Range range = StripAcceleratorChars(flags, &adjusted_text);
     bool elide_text = ((flags & NO_ELLIPSIS) == 0);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // On Linux, eliding really means fading the end of the string. But only
     // for LTR text. RTL text is still elided (on the left) with "...".
     if (elide_text) {
