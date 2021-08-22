--- chromecast/browser/cast_browser_main_parts.h.orig	2021-07-19 18:45:12 UTC
+++ chromecast/browser/cast_browser_main_parts.h
@@ -136,7 +136,7 @@ class CastBrowserMainParts : public content::BrowserMa
   std::unique_ptr<PrefService> user_pref_service_;
 #endif
 
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(USE_OZONE)
   std::unique_ptr<WaylandServerController> wayland_server_controller_;
 #endif
 
