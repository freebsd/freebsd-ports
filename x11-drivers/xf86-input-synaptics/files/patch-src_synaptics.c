--- src/synaptics.c.orig	2016-09-30 07:09:32 UTC
+++ src/synaptics.c
@@ -2599,7 +2599,7 @@ HandleScrolling(SynapticsPrivate * priv,
 
         priv->scroll.delta_y += priv->scroll.coast_speed_y * dtime * abs(para->scroll_dist_vert);
         delay = MIN(delay, POLL_MS);
-        if (abs(priv->scroll.coast_speed_y) < ddy) {
+        if (fabs(priv->scroll.coast_speed_y) < ddy) {
             priv->scroll.coast_speed_y = 0;
             priv->scroll.packets_this_scroll = 0;
         }
@@ -2614,7 +2614,7 @@ HandleScrolling(SynapticsPrivate * priv,
         double ddx = para->coasting_friction * dtime;
         priv->scroll.delta_x += priv->scroll.coast_speed_x * dtime * abs(para->scroll_dist_horiz);
         delay = MIN(delay, POLL_MS);
-        if (abs(priv->scroll.coast_speed_x) < ddx) {
+        if (fabs(priv->scroll.coast_speed_x) < ddx) {
             priv->scroll.coast_speed_x = 0;
             priv->scroll.packets_this_scroll = 0;
         }
@@ -2670,8 +2670,8 @@ clickpad_guess_clickfingers(SynapticsPri
              * really, this should be dependent on the touchpad size. Also,
              * you'll need to find a touchpad that doesn't lie about it's
              * size. Good luck. */
-            if (abs(x1 - x2) < (priv->maxx - priv->minx) * .3 &&
-                abs(y1 - y2) < (priv->maxy - priv->miny) * .3) {
+            if (fabs(x1 - x2) < (priv->maxx - priv->minx) * .3 &&
+                fabs(y1 - y2) < (priv->maxy - priv->miny) * .3) {
                 close_point |= (1 << j);
                 close_point |= (1 << i);
             }
