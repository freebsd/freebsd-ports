--- gkrellweather.c.orig	Mon Mar 31 13:12:57 2003
+++ gkrellweather.c	Sun Jul 13 14:30:14 2003
@@ -983,7 +983,7 @@
     options.windspeed_unit = 1;
     options.pressure_unit = 1;
     strcpy(options.station, DEFAULT_STATION_ID);
-    sprintf(options.command, "/usr/share/gkrellm/GrabWeather %s", options.station);
+    sprintf(options.command, "GrabWeather %s", options.station);
     sprintf(options.filename, "%s/.wmWeatherReports/%s.dat",
             getenv("HOME"), options.station);
 }
@@ -993,6 +993,7 @@
 gkrellm_init_plugin(void)
 {
     #ifdef ENABLE_NLS
+    	bindtextdomain(PACKAGE, LOCALEDIR);
         bind_textdomain_codeset(PACKAGE, "UTF-8");
     #endif /* ENABLE_NLS */
     style_id = gkrellm_add_meter_style(&air_mon, STYLE_NAME);
