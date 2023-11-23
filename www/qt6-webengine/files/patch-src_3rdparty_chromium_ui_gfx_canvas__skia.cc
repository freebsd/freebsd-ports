--- src/3rdparty/chromium/ui/gfx/canvas_skia.cc.orig	2022-02-28 16:54:41 UTC
+++ src/3rdparty/chromium/ui/gfx/canvas_skia.cc
@@ -200,7 +200,7 @@ void Canvas::DrawStringRectWithFlags(const std::u16str
     Range range = StripAcceleratorChars(flags, &adjusted_text);
     bool elide_text = ((flags & NO_ELLIPSIS) == 0);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // On Linux, eliding really means fading the end of the string. But only
     // for LTR text. RTL text is still elided (on the left) with "...".
     if (elide_text) {
