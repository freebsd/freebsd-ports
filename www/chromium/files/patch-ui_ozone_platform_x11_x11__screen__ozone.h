--- ui/ozone/platform/x11/x11_screen_ozone.h.orig	2026-09-25 15:26:43 UTC
+++ ui/ozone/platform/x11/x11_screen_ozone.h
@@ -16,7 +16,7 @@
 #include "ui/gfx/x/event.h"
 #include "ui/ozone/public/platform_screen.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/device_scale_factor_observer.h"
 #include "ui/linux/linux_ui.h"
 #endif
@@ -29,7 +29,7 @@ class X11WindowManager;
 class X11ScreenOzone : public PlatformScreen,
                        public x11::EventObserver,
                        public XDisplayManager::Delegate
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     ,
                        public DeviceScaleFactorObserver
 #endif
@@ -106,7 +106,7 @@ class X11ScreenOzone : public PlatformScreen,
   // ui::XDisplayManager::Delegate:
   void OnXDisplayListUpdated() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // DeviceScaleFactorObserver:
   void OnDeviceScaleFactorChanged() override;
 #endif
@@ -118,7 +118,7 @@ class X11ScreenOzone : public PlatformScreen,
   // Indicates that |this| is initialized.
   bool initialized_ = false;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<ui::LinuxUi, DeviceScaleFactorObserver>
       display_scale_factor_observer_{this};
 #endif
