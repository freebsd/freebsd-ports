--- ui/ozone/public/platform_screen.h.orig	2022-08-15 13:11:31 UTC
+++ ui/ozone/public/platform_screen.h
@@ -89,11 +89,27 @@ class COMPONENT_EXPORT(OZONE_BASE) PlatformScreen {
   virtual display::Display GetDisplayMatching(
       const gfx::Rect& match_rect) const = 0;
 
-  // Suspends or un-suspends the platform-specific screensaver, and returns
-  // whether the operation was successful. Can be called more than once with the
-  // same value for |suspend|, but those states should not stack: the first
-  // alternating value should toggle the state of the suspend.
-  virtual bool SetScreenSaverSuspended(bool suspend);
+  // Object which suspends the platform-specific screensaver for the duration of
+  // its existence.
+  class PlatformScreenSaverSuspender {
+   public:
+    PlatformScreenSaverSuspender() = default;
+
+    PlatformScreenSaverSuspender(const PlatformScreenSaverSuspender&) = delete;
+    PlatformScreenSaverSuspender& operator=(
+        const PlatformScreenSaverSuspender&) = delete;
+
+    // Causes the platform-specific screensaver to be un-suspended iff this is
+    // the last remaining instance.
+    virtual ~PlatformScreenSaverSuspender() = 0;
+  };
+
+  // Suspends the platform-specific screensaver until the returned
+  // |PlatformScreenSaverSuspender| is destructed, or returns nullptr if
+  // suspension failed. This method allows stacking multiple overlapping calls,
+  // such that the platform-specific screensaver will not be un-suspended until
+  // all returned |PlatformScreenSaverSuspender| instances have been destructed.
+  virtual std::unique_ptr<PlatformScreenSaverSuspender> SuspendScreenSaver();
 
   // Returns whether the screensaver is currently running.
   virtual bool IsScreenSaverActive() const;
