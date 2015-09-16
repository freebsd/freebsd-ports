--- ui/gfx/canvas_skia.cc.orig	2015-04-14 18:31:23.000000000 -0400
+++ ui/gfx/canvas_skia.cc	2015-04-28 08:45:50.095480000 -0400
@@ -287,7 +287,7 @@
     Range range = StripAcceleratorChars(flags, &adjusted_text);
     bool elide_text = ((flags & NO_ELLIPSIS) == 0);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // On Linux, eliding really means fading the end of the string. But only
     // for LTR text. RTL text is still elided (on the left) with "...".
     if (elide_text) {
