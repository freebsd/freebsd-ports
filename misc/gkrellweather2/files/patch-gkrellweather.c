--- gkrellweather.c.orig	Mon Mar 31 13:12:57 2003
+++ gkrellweather.c	Sun Jul 13 14:30:14 2003
@@ -986,7 +986,7 @@
     options.windspeed_unit = 1;
     options.pressure_unit = 1;
     strcpy(options.station, DEFAULT_STATION_ID);
-    snprintf(options.command, 512, "/usr/share/gkrellm/GrabWeather %s", options.station);
+    snprintf(options.command, 512, "GrabWeather %s", options.station);
     options.command[511] = 0;
     snprintf(options.filename, 512, "%s/.wmWeatherReports/%s.dat",
              getenv("HOME"), options.station);
@@ -998,6 +998,7 @@
 gkrellm_init_plugin(void)
 {
     #ifdef ENABLE_NLS
+        bindtextdomain(PACKAGE, LOCALEDIR);
         bind_textdomain_codeset(PACKAGE, "UTF-8");
     #endif /* ENABLE_NLS */
     style_id = gkrellm_add_meter_style(&air_mon, STYLE_NAME);
