--- panel-plugin/weather.c.orig	2020-02-23 00:39:53 UTC
+++ panel-plugin/weather.c
@@ -656,7 +656,7 @@ update_handler(plugin_data *data)
         /* build url */
         url = g_strdup_printf("https://api.met.no"
                               "/weatherapi/locationforecast/%s/"
-                              "?lat=%s&lon=%s&msl=%d",
+                              "classic?lat=%s&lon=%s&altitude=%d",
                               api_version,
                               data->lat, data->lon, data->msl);
 
