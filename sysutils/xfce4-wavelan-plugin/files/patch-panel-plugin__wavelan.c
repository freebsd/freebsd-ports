--- ./panel-plugin/wavelan.c.orig	2012-06-29 20:07:10.000000000 +0000
+++ ./panel-plugin/wavelan.c	2014-05-20 21:45:00.000000000 +0000
@@ -98,11 +98,11 @@
 
    if (wavelan->signal_colors) {
     /* set color */
-     if (state > 70)
+     if (state > 75)
       gdk_color_parse(signal_color_strong, &color);
-     else if (state > 55)
+     else if (state > 50)
       gdk_color_parse(signal_color_good, &color);
-     else if (state > 40)
+     else if (state > 25)
       gdk_color_parse(signal_color_weak, &color);
      else
       gdk_color_parse(signal_color_bad, &color);
@@ -163,7 +163,16 @@
       }
     }
     else {
-      wavelan_set_state(wavelan, stats.ws_quality);
+      if (strcmp(stats.ws_qunit, "dBm") == 0)
+        /*
+	 * Usual formula is:
+	 *	qual = 4 * (signal - noise)
+	 * where noise is typically about -96dBm, but we don't have
+	 * the actual noise value here, so approximate one.
+	 */
+        wavelan_set_state(wavelan, 4 * (stats.ws_quality - (-96)));
+      else
+        wavelan_set_state(wavelan, stats.ws_quality);
 
       if (strlen(stats.ws_netname) > 0)
         tip = g_strdup_printf("%s: %d%s at %dMb/s", stats.ws_netname, stats.ws_quality, stats.ws_qunit, stats.ws_rate);
