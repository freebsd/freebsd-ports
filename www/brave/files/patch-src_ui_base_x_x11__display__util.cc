--- src/ui/base/x/x11_display_util.cc.orig	2026-09-25 15:26:43 UTC
+++ src/ui/base/x/x11_display_util.cc
@@ -248,7 +248,13 @@ float GetDisplayScale(const gfx::Rect& b
         RectDistance(geometry.bounds_px, bounds), geometry.scale);
     min_dist_scale = std::min(min_dist_scale, dist_scale);
   }
-  return min_dist_scale.second;
+  // The scale includes the font scale, Xft.dpi / 96, which drops below 1 when
+  // the desktop sets a DPI under 96 (MATE, for one, derives it from the
+  // monitor size).  Nothing here expects that -- see the DCHECK in
+  // GetFallbackDisplayList() -- and with it the displays grow larger than the
+  // screen in DIPs and overlap, popups are sized to thousands of pixels
+  // outside the screen and Xorg spins compositing them, freezing the desktop.
+  return std::max(1.0f, min_dist_scale.second);
 }
 
 gfx::PointF DisplayOriginPxToDip(const display::Display& parent,
@@ -322,7 +328,8 @@ std::vector<display::Display> BuildDispl
     size_t* primary_display_index_out) {
   DCHECK(primary_display_index_out);
   auto* command_line = base::CommandLine::ForCurrentProcess();
-  const float primary_scale = display_config.primary_scale;
+  // Never below 1, see GetDisplayScale().
+  const float primary_scale = std::max(1.0f, display_config.primary_scale);
 
   auto* connection = x11::Connection::Get();
   DCHECK(connection->randr_version() >= kMinVersionXrandr);
