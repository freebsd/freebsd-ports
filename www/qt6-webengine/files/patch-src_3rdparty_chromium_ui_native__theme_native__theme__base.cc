--- src/3rdparty/chromium/ui/native_theme/native_theme_base.cc.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/ui/native_theme/native_theme_base.cc
@@ -273,7 +273,7 @@ void NativeThemeBase::Paint(cc::PaintCanvas* canvas,
       break;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect, extra.frame_top_area,
                         color_scheme);
