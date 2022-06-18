--- ui/display/screen.h.orig	2022-06-17 14:20:10 UTC
+++ ui/display/screen.h
@@ -120,7 +120,7 @@ class DISPLAY_EXPORT Screen {
   // (both of which may or may not be `nearest_id`).
   display::ScreenInfos GetScreenInfosNearestDisplay(int64_t nearest_id) const;
 
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Object which suspends the platform-specific screensaver for the duration of
   // its existence.
   class ScreenSaverSuspender {
@@ -192,7 +192,7 @@ class DISPLAY_EXPORT Screen {
       const gfx::GpuExtraInfo& gpu_extra_info);
 
  protected:
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Suspends or un-suspends the platform-specific screensaver, and returns
   // whether the operation was successful.
   virtual bool SetScreenSaverSuspended(bool suspend);
@@ -211,7 +211,7 @@ class DISPLAY_EXPORT Screen {
   int64_t display_id_for_new_windows_;
   int64_t scoped_display_id_for_new_windows_ = display::kInvalidDisplayId;
 
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   uint32_t screen_saver_suspension_count_ = 0;
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
 };
