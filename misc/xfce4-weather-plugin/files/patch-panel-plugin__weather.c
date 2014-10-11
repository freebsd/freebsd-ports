Make plugin ready for met.no locationforecast-1.2 API (bug #10916).

--- panel-plugin/weather.c.orig	2013-02-18 10:21:00 UTC
+++ panel-plugin/weather.c
@@ -638,7 +638,7 @@
         /* build url */
         url =
             g_strdup_printf("http://api.yr.no/weatherapi"
-                            "/locationforecastlts/1.1/?lat=%s;lon=%s;msl=%d",
+                            "/locationforecastlts/1.2/?lat=%s;lon=%s;msl=%d",
                             data->lat, data->lon, data->msl);
 
         /* start receive thread */
