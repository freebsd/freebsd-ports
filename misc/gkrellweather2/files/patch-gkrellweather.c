--- gkrellweather.c.orig	Sun Nov 24 04:49:42 2002
+++ gkrellweather.c	Sun Nov 24 04:50:58 2002
@@ -720,7 +720,7 @@
         options.station[1] = c[1];
         options.station[2] = c[2];
         options.station[3] = c[3];
-        sprintf(options.command, "/usr/local/bin/GrabWeather %s", options.station);
+        sprintf(options.command, "GrabWeather %s", options.station);
         sprintf(options.filename, "%s/.wmWeatherReports/%s.dat",
                 getenv("HOME"), options.station);
 	net_update = FALSE;
@@ -981,7 +981,7 @@
     options.windspeed_unit = 1;
     options.pressure_unit = 1;
     strcpy(options.station, DEFAULT_STATION_ID);
-    sprintf(options.command, "/usr/share/gkrellm/GrabWeather %s", options.station);
+    sprintf(options.command, "GrabWeather %s", options.station);
     sprintf(options.filename, "%s/.wmWeatherReports/%s.dat",
             getenv("HOME"), options.station);
 }
