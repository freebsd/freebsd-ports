--- ./midori/main.c.orig	2012-09-19 21:17:43.000000000 +0000
+++ ./midori/main.c	2012-09-21 19:10:59.000000000 +0000
@@ -1027,9 +1027,6 @@
     g_signal_connect (session, "request-queued",
         G_CALLBACK (midori_soup_session_settings_accept_language_cb), settings);
 
-    soup_session_add_feature (session, SOUP_SESSION_FEATURE (
-        midori_hsts_new (midori_paths_get_readonly_config_filename ("hsts"))));
-
     midori_soup_session_debug (session);
 
     g_object_set_data (G_OBJECT (session), "midori-session-initialized", (void*)1);
@@ -1430,8 +1427,9 @@
     {
         katze_item_set_meta_integer (item, "append", 1);
         katze_item_set_meta_integer (item, "dont-write-history", 1);
-        if (load_on_startup == MIDORI_STARTUP_DELAYED_PAGES)
-            katze_item_set_meta_integer (item, "delay", 1);
+        if (load_on_startup == MIDORI_STARTUP_DELAYED_PAGES
+         || katze_item_get_meta_integer (item, "delay") == MIDORI_DELAY_PENDING_UNDELAY)
+            katze_item_set_meta_integer (item, "delay", MIDORI_DELAY_DELAYED);
         midori_browser_add_item (browser, item);
     }
     current = katze_item_get_meta_integer (KATZE_ITEM (_session), "current");
