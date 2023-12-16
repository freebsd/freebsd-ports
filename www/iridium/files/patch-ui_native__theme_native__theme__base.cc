--- ui/native_theme/native_theme_base.cc.orig	2023-11-22 14:00:11 UTC
+++ ui/native_theme/native_theme_base.cc
@@ -235,7 +235,7 @@ void NativeThemeBase::Paint(cc::PaintCanvas* canvas,
       break;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect,
                         absl::get<FrameTopAreaExtraParams>(extra),
