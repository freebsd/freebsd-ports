--- ui/native_theme/native_theme_base.cc.orig	2025-10-21 16:57:35 UTC
+++ ui/native_theme/native_theme_base.cc
@@ -238,7 +238,7 @@ void NativeThemeBase::Paint(cc::PaintCanvas* canvas,
                     std::get<ButtonExtraParams>(extra), color_scheme,
                     accent_color_opaque);
       break;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect,
                         std::get<FrameTopAreaExtraParams>(extra), color_scheme);
