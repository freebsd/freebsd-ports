--- ui/ozone/platform/x11/x11_screen_ozone.h.orig	2022-08-15 13:11:31 UTC
+++ ui/ozone/platform/x11/x11_screen_ozone.h
@@ -50,7 +50,8 @@ class X11ScreenOzone : public PlatformScreen,
       const gfx::Point& point) const override;
   display::Display GetDisplayMatching(
       const gfx::Rect& match_rect) const override;
-  bool SetScreenSaverSuspended(bool suspend) override;
+  std::unique_ptr<PlatformScreen::PlatformScreenSaverSuspender>
+  SuspendScreenSaver() override;
   bool IsScreenSaverActive() const override;
   base::TimeDelta CalculateIdleTime() const override;
   void AddObserver(display::DisplayObserver* observer) override;
@@ -65,6 +66,22 @@ class X11ScreenOzone : public PlatformScreen,
 
  private:
   friend class X11ScreenOzoneTest;
+
+  class X11ScreenSaverSuspender
+      : public PlatformScreen::PlatformScreenSaverSuspender {
+   public:
+    X11ScreenSaverSuspender(const X11ScreenSaverSuspender&) = delete;
+    X11ScreenSaverSuspender& operator=(const X11ScreenSaverSuspender&) = delete;
+
+    ~X11ScreenSaverSuspender() override;
+
+    static std::unique_ptr<X11ScreenSaverSuspender> Create();
+
+   private:
+    X11ScreenSaverSuspender();
+
+    bool is_suspending_ = false;
+  };
 
   // Overridden from ui::XDisplayManager::Delegate:
   void OnXDisplayListUpdated() override;
