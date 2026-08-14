--- ui/native_theme/native_theme_base.cc.orig	2026-08-13 16:48:13 UTC
+++ ui/native_theme/native_theme_base.cc
@@ -167,7 +167,7 @@ void NativeThemeBase::PaintImpl(cc::PaintCanvas* canva
                     std::get<ButtonExtraParams>(extra_params), dark_mode,
                     contrast, accent_color);
       break;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect,
                         std::get<FrameTopAreaExtraParams>(extra_params));
