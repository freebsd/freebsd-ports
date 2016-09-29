--- libmateweather/weather-iwin.c.orig	2016-09-29 14:03:12.143111000 +0200
+++ libmateweather/weather-iwin.c	2016-09-29 14:03:35.883636000 +0200
@@ -462,7 +462,7 @@ iwin_start_open (WeatherInfo *info)
     zone = g_ascii_strdown (loc->zone, -1);
     state = g_strndup (zone, 2);
 
-    url = g_strdup_printf ("http://weather.noaa.gov/pub/data/forecasts/zone/%s/%s.txt", state, zone);
+    url = g_strdup_printf ("http://tgftp.nws.noaa.gov/data/forecasts/zone/%s/%s.txt", state, zone);
 
     g_free (zone);
     g_free (state);
