--- libmateweather/weather-metar.c.orig	2016-09-29 14:03:25.503926000 +0200
+++ libmateweather/weather-metar.c	2016-09-29 14:03:40.232655000 +0200
@@ -510,7 +510,7 @@ metar_finish (SoupSession *session, Soup
 
     loc = info->location;
 
-    searchkey = g_strdup_printf ("\n%s", loc->code);
+    searchkey = g_strdup_printf ("<raw_text>%s", loc->code);
     p = strstr (msg->response_body->data, searchkey);
     g_free (searchkey);
     if (p) {
@@ -522,8 +522,8 @@ metar_finish (SoupSession *session, Soup
 	    metar = g_strdup (p);
 	success = metar_parse (metar, info);
 	g_free (metar);
-    } else if (!strstr (msg->response_body->data, "National Weather Service")) {
-	/* The response doesn't even seem to have come from NWS...
+    } else if (!strstr (msg->response_body->data, "aviationweather.gov")) {
+	/* The response doesn't even seem to have come from NOAA...
 	 * most likely it is a wifi hotspot login page. Call that a
 	 * network error.
 	 */
@@ -550,8 +550,14 @@ metar_start_open (WeatherInfo *info)
     }
 
     msg = soup_form_request_new (
-	"GET", "http://weather.noaa.gov/mgetmetar.php",
-	"cccc", loc->code,
+	"GET", "https://www.aviationweather.gov/adds/dataserver_current/httpparam",
+	"dataSource", "metars",
+	"requestType", "retrieve",
+	"format", "xml",
+	"hoursBeforeNow", "3",
+	"mostRecent", "true",
+	"fields", "raw_text",
+	"stationString", loc->code,
 	NULL);
     soup_session_queue_message (info->session, msg, metar_finish, info);
 
