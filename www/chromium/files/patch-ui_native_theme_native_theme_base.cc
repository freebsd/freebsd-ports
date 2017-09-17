--- ui/native_theme/native_theme_base.cc.orig	2017-09-07 02:01:55.087892000 +0200
+++ ui/native_theme/native_theme_base.cc	2017-09-07 02:02:23.038570000 +0200
@@ -172,7 +172,7 @@
     case kCheckbox:
       PaintCheckbox(canvas, state, rect, extra.button);
       break;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect, extra.frame_top_area);
       break;
