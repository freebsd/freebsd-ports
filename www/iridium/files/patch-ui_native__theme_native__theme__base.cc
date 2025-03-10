--- ui/native_theme/native_theme_base.cc.orig	2025-02-22 18:06:53 UTC
+++ ui/native_theme/native_theme_base.cc
@@ -238,7 +238,7 @@ void NativeThemeBase::Paint(cc::PaintCanvas* canvas,
                     absl::get<ButtonExtraParams>(extra), color_scheme,
                     accent_color_opaque);
       break;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect,
                         absl::get<FrameTopAreaExtraParams>(extra),
