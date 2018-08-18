--- ui/views/widget/desktop_aura/desktop_screen_x11.cc.orig	2018-06-13 00:11:10.000000000 +0200
+++ ui/views/widget/desktop_aura/desktop_screen_x11.cc	2018-07-20 17:57:12.071809000 +0200
@@ -216,8 +216,13 @@
   if (host) {
     DesktopWindowTreeHostX11* rwh = DesktopWindowTreeHostX11::GetHostForXID(
         host->GetAcceleratedWidget());
-    if (rwh)
-      return GetDisplayMatching(rwh->GetX11RootWindowBounds());
+    if (rwh) {
+      const float scale = 1.0f / GetDeviceScaleFactor();
+      const gfx::Rect pixel_rect = rwh->GetX11RootWindowBounds();
+      return GetDisplayMatching(
+          gfx::Rect(gfx::ScaleToFlooredPoint(pixel_rect.origin(), scale),
+                    gfx::ScaleToCeiledSize(pixel_rect.size(), scale)));
+    }
   }
 
   return GetPrimaryDisplay();
