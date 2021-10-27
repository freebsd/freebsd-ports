--- ui/native_theme/native_theme_base.cc.orig	2021-09-24 04:26:39 UTC
+++ ui/native_theme/native_theme_base.cc
@@ -267,7 +267,7 @@ void NativeThemeBase::Paint(cc::PaintCanvas* canvas,
       break;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect, extra.frame_top_area,
                         color_scheme);
