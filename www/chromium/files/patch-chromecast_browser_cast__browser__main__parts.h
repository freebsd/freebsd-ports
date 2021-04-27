--- chromecast/browser/cast_browser_main_parts.h.orig	2021-04-14 18:40:58 UTC
+++ chromecast/browser/cast_browser_main_parts.h
@@ -133,7 +133,7 @@ class CastBrowserMainParts : public content::BrowserMa
   std::unique_ptr<PrefService> user_pref_service_;
 #endif
 
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(USE_OZONE)
   std::unique_ptr<WaylandServerController> wayland_server_controller_;
 #endif
 
