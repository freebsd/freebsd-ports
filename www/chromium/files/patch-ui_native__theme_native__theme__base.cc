--- ui/native_theme/native_theme_base.cc.orig	2019-10-21 19:07:29 UTC
+++ ui/native_theme/native_theme_base.cc
@@ -177,7 +177,7 @@ void NativeThemeBase::Paint(cc::PaintCanvas* canvas,
     case kCheckbox:
       PaintCheckbox(canvas, state, rect, extra.button, color_scheme);
       break;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect, extra.frame_top_area,
                         color_scheme);
