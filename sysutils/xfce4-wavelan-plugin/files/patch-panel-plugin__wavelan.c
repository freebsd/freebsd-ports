--- panel-plugin/wavelan.c.orig	2016-10-29 06:46:02 UTC
+++ panel-plugin/wavelan.c
@@ -99,11 +99,11 @@ wavelan_set_state(t_wavelan *wavelan, gi
 
    if (wavelan->signal_colors) {
     /* set color */
-     if (state > 70)
+     if (state > 75)
       gdk_rgba_parse(&color, signal_color_strong);
-     else if (state > 55)
+     else if (state > 50)
       gdk_rgba_parse(&color, signal_color_good);
-     else if (state > 40)
+     else if (state > 25)
       gdk_rgba_parse(&color, signal_color_weak);
      else
       gdk_rgba_parse(&color, signal_color_bad);
@@ -183,7 +183,15 @@ wavelan_timer(gpointer data)
       }
     }
     else {
-      wavelan_set_state(wavelan, stats.ws_quality);
+      /*
+       * Usual formula is: qual = 4 * (signal - noise)
+       * where noise is typically about -96dBm, but we don't have
+       * the actual noise value here, so approximate one.
+       */
+      if (strcmp(stats.ws_qunit, "dBm") == 0)
+        wavelan_set_state(wavelan, 4 * (stats.ws_quality - (-96)));
+      else
+        wavelan_set_state(wavelan, stats.ws_quality);
 
       if (strlen(stats.ws_netname) > 0)
         /* Translators: net_name: quality quality_unit at rate Mb/s*/
