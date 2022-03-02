--- content/browser/renderer_host/render_view_host_impl.cc.orig	2022-02-28 16:54:41 UTC
+++ content/browser/renderer_host/render_view_host_impl.cc
@@ -259,7 +259,7 @@ void RenderViewHostImpl::GetPlatformSpecificPrefs(
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CYVSCROLL);
   prefs->arrow_bitmap_width_horizontal_scroll_bar_in_dips =
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CXHSCROLL);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   prefs->system_font_family_name = gfx::Font().GetFontName();
 #elif BUILDFLAG(IS_FUCHSIA)
   // Make Blink's "focus ring" invisible. The focus ring is a hairline border
