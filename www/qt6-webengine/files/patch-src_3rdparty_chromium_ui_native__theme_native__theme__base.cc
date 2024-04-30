--- src/3rdparty/chromium/ui/native_theme/native_theme_base.cc.orig	2023-10-11 18:22:24 UTC
+++ src/3rdparty/chromium/ui/native_theme/native_theme_base.cc
@@ -275,7 +275,7 @@ void NativeThemeBase::Paint(cc::PaintCanvas* canvas,
       break;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect,
                         absl::get<FrameTopAreaExtraParams>(extra),
