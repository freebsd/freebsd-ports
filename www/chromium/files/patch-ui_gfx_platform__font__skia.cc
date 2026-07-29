--- ui/gfx/platform_font_skia.cc.orig	2026-08-12 09:02:10 UTC
+++ ui/gfx/platform_font_skia.cc
@@ -29,7 +29,7 @@
 #include "ui/gfx/system_fonts_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -170,7 +170,7 @@ void PlatformFontSkia::EnsuresDefaultFontIsInitialized
   weight = system_font.GetWeight();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, LinuxUi is used to query the native toolkit (e.g.
   // GTK) for the default UI font.
   if (auto* linux_ui = ui::LinuxUi::instance()) {
@@ -329,7 +329,7 @@ const FontRenderParams& PlatformFontSkia::GetFontRende
   TRACE_EVENT0("fonts", "PlatformFontSkia::GetFontRenderParams");
   float current_scale_factor = GetFontRenderParamsDeviceScaleFactor();
   bool force_query = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const bool current_subpixel_rendering_enabled =
       gfx::GetFontRenderParamsSubpixelRenderingEnabled();
   if (current_subpixel_rendering_enabled != subpixel_rendering_enabled_) {
@@ -346,7 +346,7 @@ const FontRenderParams& PlatformFontSkia::GetFontRende
     query.device_scale_factor = current_scale_factor;
     font_render_params_ = gfx::GetFontRenderParams(query, nullptr);
     device_scale_factor_ = current_scale_factor;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     subpixel_rendering_enabled_ = current_subpixel_rendering_enabled;
 #endif
   }
@@ -399,7 +399,7 @@ void PlatformFontSkia::InitFromDetails(sk_sp<SkTypefac
   style_ = style;
   weight_ = weight;
   device_scale_factor_ = GetFontRenderParamsDeviceScaleFactor();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   subpixel_rendering_enabled_ =
       gfx::GetFontRenderParamsSubpixelRenderingEnabled();
 #endif
@@ -415,7 +415,7 @@ void PlatformFontSkia::InitFromPlatformFont(const Plat
   style_ = other->style_;
   weight_ = other->weight_;
   device_scale_factor_ = other->device_scale_factor_;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   subpixel_rendering_enabled_ = other->subpixel_rendering_enabled_;
 #endif
   font_render_params_ = other->font_render_params_;
