--- content/browser/renderer_host/render_view_host_impl.cc.orig	2017-02-02 02:02:53 UTC
+++ content/browser/renderer_host/render_view_host_impl.cc
@@ -139,7 +139,7 @@ void GetPlatformSpecificPrefs(RendererPr
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CYVSCROLL);
   prefs->arrow_bitmap_width_horizontal_scroll_bar_in_dips =
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CXHSCROLL);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   prefs->system_font_family_name = gfx::Font().GetFontName();
 #endif
 }
