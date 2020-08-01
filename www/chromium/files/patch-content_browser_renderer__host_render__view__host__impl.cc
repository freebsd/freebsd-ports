--- content/browser/renderer_host/render_view_host_impl.cc.orig	2020-07-07 21:58:15 UTC
+++ content/browser/renderer_host/render_view_host_impl.cc
@@ -227,7 +227,7 @@ void RenderViewHostImpl::GetPlatformSpecificPrefs(
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CYVSCROLL);
   prefs->arrow_bitmap_width_horizontal_scroll_bar_in_dips =
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CXHSCROLL);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   prefs->system_font_family_name = gfx::Font().GetFontName();
 #elif defined(OS_FUCHSIA)
   // Make Blink's "focus ring" invisible. The focus ring is a hairline border
