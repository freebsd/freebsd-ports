--- src/3rdparty/chromium/ui/native_theme/native_theme_base.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/native_theme/native_theme_base.cc
@@ -172,7 +172,7 @@ void NativeThemeBase::Paint(cc::PaintCanvas* canvas,
     case kCheckbox:
       PaintCheckbox(canvas, state, rect, extra.button);
       break;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect, extra.frame_top_area);
       break;
