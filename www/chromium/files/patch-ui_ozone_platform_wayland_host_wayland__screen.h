--- ui/ozone/platform/wayland/host/wayland_screen.h.orig	2022-08-15 13:11:31 UTC
+++ ui/ozone/platform/wayland/host/wayland_screen.h
@@ -68,7 +68,8 @@ class WaylandScreen : public PlatformScreen {
       const gfx::Point& point) const override;
   display::Display GetDisplayMatching(
       const gfx::Rect& match_rect) const override;
-  bool SetScreenSaverSuspended(bool suspend) override;
+  std::unique_ptr<PlatformScreen::PlatformScreenSaverSuspender>
+  SuspendScreenSaver() override;
   bool IsScreenSaverActive() const override;
   base::TimeDelta CalculateIdleTime() const override;
   void AddObserver(display::DisplayObserver* observer) override;
@@ -76,7 +77,33 @@ class WaylandScreen : public PlatformScreen {
   std::vector<base::Value> GetGpuExtraInfo(
       const gfx::GpuExtraInfo& gpu_extra_info) override;
 
+ protected:
+  // Suspends or un-suspends the platform-specific screensaver, and returns
+  // whether the operation was successful. Can be called more than once with the
+  // same value for |suspend|, but those states should not stack: the first
+  // alternating value should toggle the state of the suspend.
+  bool SetScreenSaverSuspended(bool suspend);
+
  private:
+  class WaylandScreenSaverSuspender
+      : public PlatformScreen::PlatformScreenSaverSuspender {
+   public:
+    WaylandScreenSaverSuspender(const WaylandScreenSaverSuspender&) = delete;
+    WaylandScreenSaverSuspender& operator=(const WaylandScreenSaverSuspender&) =
+        delete;
+
+    ~WaylandScreenSaverSuspender() override;
+
+    static std::unique_ptr<WaylandScreenSaverSuspender> Create(
+        WaylandScreen& screen);
+
+   private:
+    explicit WaylandScreenSaverSuspender(WaylandScreen& screen);
+
+    base::WeakPtr<WaylandScreen> screen_;
+    bool is_suspending_ = false;
+  };
+
   // All parameters are in DIP screen coordinates/units except |physical_size|,
   // which is in physical pixels.
   void AddOrUpdateDisplay(uint32_t output_id,
@@ -103,6 +130,7 @@ class WaylandScreen : public PlatformScreen {
 #endif
 
   wl::Object<zwp_idle_inhibitor_v1> idle_inhibitor_;
+  uint32_t screen_saver_suspension_count_ = 0;
 
   base::WeakPtrFactory<WaylandScreen> weak_factory_;
 };
