--- ui/aura/screen_ozone.h.orig	2022-06-17 14:20:10 UTC
+++ ui/aura/screen_ozone.h
@@ -63,7 +63,7 @@ class AURA_EXPORT ScreenOzone : public display::Screen
  protected:
   ui::PlatformScreen* platform_screen() { return platform_screen_.get(); }
 
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool SetScreenSaverSuspended(bool suspend) override;
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
 
