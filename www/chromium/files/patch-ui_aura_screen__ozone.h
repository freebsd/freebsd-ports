--- ui/aura/screen_ozone.h.orig	2022-08-15 13:11:31 UTC
+++ ui/aura/screen_ozone.h
@@ -11,11 +11,8 @@
 #include "build/chromeos_buildflags.h"
 #include "ui/aura/aura_export.h"
 #include "ui/display/screen.h"
+#include "ui/ozone/public/platform_screen.h"
 
-namespace ui {
-class PlatformScreen;
-}
-
 namespace aura {
 
 // display::Screen implementation on top of ui::PlatformScreen provided by
@@ -48,6 +45,10 @@ class AURA_EXPORT ScreenOzone : public display::Screen
   display::Display GetDisplayMatching(
       const gfx::Rect& match_rect) const override;
   display::Display GetPrimaryDisplay() const override;
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
+  std::unique_ptr<display::Screen::ScreenSaverSuspender> SuspendScreenSaver()
+      override;
+#endif  // BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
   bool IsScreenSaverActive() const override;
   base::TimeDelta CalculateIdleTime() const override;
   void AddObserver(display::DisplayObserver* observer) override;
@@ -65,11 +66,27 @@ class AURA_EXPORT ScreenOzone : public display::Screen
  protected:
   ui::PlatformScreen* platform_screen() { return platform_screen_.get(); }
 
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
-  bool SetScreenSaverSuspended(bool suspend) override;
+ private:
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
+  class ScreenSaverSuspenderOzone
+      : public display::Screen::ScreenSaverSuspender {
+   public:
+    explicit ScreenSaverSuspenderOzone(
+        std::unique_ptr<ui::PlatformScreen::PlatformScreenSaverSuspender>
+            suspender);
+
+    ScreenSaverSuspenderOzone(const ScreenSaverSuspenderOzone&) = delete;
+    ScreenSaverSuspenderOzone& operator=(const ScreenSaverSuspenderOzone&) =
+        delete;
+
+    ~ScreenSaverSuspenderOzone() override;
+
+   private:
+    std::unique_ptr<ui::PlatformScreen::PlatformScreenSaverSuspender>
+        suspender_;
+  };
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
 
- private:
   gfx::AcceleratedWidget GetAcceleratedWidgetForWindow(
       aura::Window* window) const;
 
