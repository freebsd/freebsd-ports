--- content/browser/renderer_host/render_view_host_impl.cc.orig	2017-06-05 19:03:07 UTC
+++ content/browser/renderer_host/render_view_host_impl.cc
@@ -142,7 +142,7 @@ void GetPlatformSpecificPrefs(RendererPreferences* pre
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CYVSCROLL);
   prefs->arrow_bitmap_width_horizontal_scroll_bar_in_dips =
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CXHSCROLL);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   prefs->system_font_family_name = gfx::Font().GetFontName();
 #endif
 }
