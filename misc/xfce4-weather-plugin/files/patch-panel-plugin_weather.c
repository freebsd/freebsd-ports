--- panel-plugin/weather.c.orig	2017-02-16 18:59:12 UTC
+++ panel-plugin/weather.c
@@ -1849,6 +1849,8 @@ xfceweather_create_control(XfcePanelPlugin *plugin)
 
     /* Setup session for HTTP connections */
     data->session = soup_session_async_new();
+    g_object_set(data->session, SOUP_SESSION_USER_AGENT,
+                 PACKAGE_NAME "-" PACKAGE_VERSION, NULL);
     g_object_set(data->session, SOUP_SESSION_TIMEOUT,
                  CONN_TIMEOUT, NULL);
 
