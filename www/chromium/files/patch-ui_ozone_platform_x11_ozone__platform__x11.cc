--- ui/ozone/platform/x11/ozone_platform_x11.cc.orig	2021-12-16 15:22:38 UTC
+++ ui/ozone/platform/x11/ozone_platform_x11.cc
@@ -211,7 +211,7 @@ class OzonePlatformX11 : public OzonePlatform,
       properties->supports_global_application_menus = true;
       properties->app_modal_dialogs_use_event_blocker = true;
       properties->fetch_buffer_formats_for_gmb_on_gpu = true;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       properties->supports_vaapi = true;
 #endif
 
