--- panel-plugin/weather.c.orig	2019-08-11 19:23:40 UTC
+++ panel-plugin/weather.c
@@ -588,6 +588,7 @@ cb_weather_update(SoupSession *session,
 static gboolean
 update_handler(plugin_data *data)
 {
+    gchar *api_version = FORECAST_API;
     gchar *url;
     gboolean night_time;
     time_t now_t;
@@ -653,9 +654,10 @@ update_handler(plugin_data *data)
         data->weather_update->started = TRUE;
 
         /* build url */
-        url = g_strdup_printf("https://api.met.no/weatherapi"
-                              "/locationforecastlts/1.3/?lat=%s&lon=%s&"
-                              "msl=%d",
+        url = g_strdup_printf("https://api.met.no"
+                              "/weatherapi/locationforecast/%s/"
+                              "?lat=%s&lon=%s&msl=%d",
+                              api_version,
                               data->lat, data->lon, data->msl);
 
         /* start receive thread */
@@ -1928,7 +1930,7 @@ xfceweather_create_control(XfcePanelPlugin *plugin)
     data->labels = g_array_new(FALSE, TRUE, sizeof(data_types));
 
     /* create panel toggle button which will contain all other widgets */
-    data->button = xfce_create_panel_toggle_button();
+    data->button = xfce_panel_create_toggle_button();
     gtk_container_add(GTK_CONTAINER(plugin), data->button);
     xfce_panel_plugin_add_action_widget(plugin, data->button);
     gtk_widget_show(data->button);
