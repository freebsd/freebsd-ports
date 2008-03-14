--- panel-plugin/wavelan.c.orig	2007-01-10 21:23:05.000000000 +0100
+++ panel-plugin/wavelan.c	2008-01-28 23:16:14.000000000 +0100
@@ -219,9 +219,9 @@
         wavelan_set_state(wavelan, STATE_LINK0);
 
       if (strlen(stats.ws_netname) > 0)
-        tip = g_strdup_printf("%d%% (%s)", stats.ws_quality, stats.ws_netname);
+        tip = g_strdup_printf("%s\n%s: %d%% at %dMB/s", stats.ws_vendor, stats.ws_netname, stats.ws_quality, stats.ws_rate);
       else
-        tip = g_strdup_printf("%d%%", stats.ws_quality);
+        tip = g_strdup_printf("%s\n%d%% at %dMB/s", stats.ws_vendor, stats.ws_quality, stats.ws_rate);
     }
   }
   else {
