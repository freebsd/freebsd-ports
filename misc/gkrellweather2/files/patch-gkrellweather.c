--- gkrellweather.c.orig	2009-01-11 18:15:02 UTC
+++ gkrellweather.c
@@ -777,7 +777,7 @@ create_air_tab (GtkWidget *tab)
         " switch interval - number of seconds (0 = never)" \
         " between switching display\n")
     };
-    static gchar url[] = "http://www.nws.noaa.gov/tg/siteloc.shtml";
+    static gchar url[] = "http://www.nws.noaa.gov/tg/siteloc.php";
     laptop = gtk_notebook_new();
     gtk_notebook_set_tab_pos(GTK_NOTEBOOK(laptop), GTK_POS_TOP);
     gtk_box_pack_start(GTK_BOX(tab), laptop, TRUE, TRUE, 0);
@@ -986,7 +986,7 @@ read_default(void)
     options.windspeed_unit = 1;
     options.pressure_unit = 1;
     strcpy(options.station, DEFAULT_STATION_ID);
-    snprintf(options.command, 512, "/usr/share/gkrellm/GrabWeather %s", options.station);
+    snprintf(options.command, 512, "GrabWeather %s", options.station);
     options.command[511] = 0;
     snprintf(options.filename, 512, "%s/.wmWeatherReports/%s.dat",
              getenv("HOME"), options.station);
@@ -998,6 +998,7 @@ GkrellmMonitor *
 gkrellm_init_plugin(void)
 {
     #ifdef ENABLE_NLS
+        bindtextdomain(PACKAGE, LOCALEDIR);
         bind_textdomain_codeset(PACKAGE, "UTF-8");
     #endif /* ENABLE_NLS */
     style_id = gkrellm_add_meter_style(&air_mon, STYLE_NAME);
