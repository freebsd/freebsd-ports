--- ui/aura/screen_ozone.h.orig	2022-07-22 17:30:31 UTC
+++ ui/aura/screen_ozone.h
@@ -65,7 +65,7 @@ class AURA_EXPORT ScreenOzone : public display::Screen
  protected:
   ui::PlatformScreen* platform_screen() { return platform_screen_.get(); }
 
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool SetScreenSaverSuspended(bool suspend) override;
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
 
