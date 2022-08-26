--- ui/display/screen.h.orig	2022-08-15 13:11:31 UTC
+++ ui/display/screen.h
@@ -128,33 +128,27 @@ class DISPLAY_EXPORT Screen {
   // (both of which may or may not be `nearest_id`).
   display::ScreenInfos GetScreenInfosNearestDisplay(int64_t nearest_id) const;
 
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Object which suspends the platform-specific screensaver for the duration of
   // its existence.
   class ScreenSaverSuspender {
    public:
-    ScreenSaverSuspender(const Screen&) = delete;
-    ScreenSaverSuspender& operator=(const Screen&) = delete;
+    ScreenSaverSuspender() = default;
 
-    // Notifies |screen_| that this instance is being destructed, and causes its
-    // platform-specific screensaver to be un-suspended if this is the last such
-    // remaining instance.
-    ~ScreenSaverSuspender();
+    ScreenSaverSuspender(const ScreenSaverSuspender&) = delete;
+    ScreenSaverSuspender& operator=(const ScreenSaverSuspender&) = delete;
 
-   private:
-    friend class Screen;
-
-    explicit ScreenSaverSuspender(Screen* screen) : screen_(screen) {}
-
-    Screen* screen_;
+    // Causes the platform-specific screensaver to be un-suspended iff this is
+    // the last remaining instance.
+    virtual ~ScreenSaverSuspender() = 0;
   };
 
   // Suspends the platform-specific screensaver until the returned
-  // |ScreenSaverSuspender| is destructed. This method allows stacking multiple
-  // overlapping calls, such that the platform-specific screensaver will not be
-  // un-suspended until all returned |SreenSaverSuspender| instances have been
-  // destructed.
-  std::unique_ptr<ScreenSaverSuspender> SuspendScreenSaver();
+  // |ScreenSaverSuspender| is destructed, or returns nullptr if suspension
+  // failed. This method allows stacking multiple overlapping calls, such that
+  // the platform-specific screensaver will not be un-suspended until all
+  // returned |ScreenSaverSuspender| instances have been destructed.
+  virtual std::unique_ptr<ScreenSaverSuspender> SuspendScreenSaver();
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
 
   // Returns whether the screensaver is currently running.
@@ -200,12 +194,6 @@ class DISPLAY_EXPORT Screen {
       const gfx::GpuExtraInfo& gpu_extra_info);
 
  protected:
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
-  // Suspends or un-suspends the platform-specific screensaver, and returns
-  // whether the operation was successful.
-  virtual bool SetScreenSaverSuspended(bool suspend);
-#endif  // BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
-
   void set_shutdown(bool shutdown) { shutdown_ = shutdown; }
 
  private:
@@ -224,7 +212,7 @@ class DISPLAY_EXPORT Screen {
   int64_t display_id_for_new_windows_;
   int64_t scoped_display_id_for_new_windows_ = display::kInvalidDisplayId;
 
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   uint32_t screen_saver_suspension_count_ = 0;
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
 };
