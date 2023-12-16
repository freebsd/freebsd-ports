--- ui/ozone/platform/x11/x11_screen_ozone.h.orig	2023-11-22 14:00:11 UTC
+++ ui/ozone/platform/x11/x11_screen_ozone.h
@@ -102,7 +102,7 @@ class X11ScreenOzone : public PlatformScreen,
   // Indicates that |this| is initialized.
   bool initialized_ = false;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<ui::LinuxUi, DeviceScaleFactorObserver>
       display_scale_factor_observer_{this};
 #endif
