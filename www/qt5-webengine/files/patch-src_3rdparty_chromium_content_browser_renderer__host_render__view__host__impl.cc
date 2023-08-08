--- src/3rdparty/chromium/content/browser/renderer_host/render_view_host_impl.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/browser/renderer_host/render_view_host_impl.cc
@@ -278,7 +278,7 @@ void RenderViewHostImpl::GetPlatformSpecificPrefs(
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CYVSCROLL);
   prefs->arrow_bitmap_width_horizontal_scroll_bar_in_dips =
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CXHSCROLL);
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   prefs->system_font_family_name = gfx::Font().GetFontName();
 #elif defined(OS_FUCHSIA)
   // Make Blink's "focus ring" invisible. The focus ring is a hairline border
