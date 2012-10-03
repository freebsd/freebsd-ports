--- ./midori/midori-view.c.orig	2012-09-19 21:17:43.000000000 +0000
+++ ./midori/midori-view.c	2012-09-21 14:22:48.000000000 +0000
@@ -1025,6 +1025,9 @@
     #endif
     view->special = FALSE;
 
+    if (katze_item_get_meta_integer (view->item, "delay") == MIDORI_DELAY_PENDING_UNDELAY)
+        katze_item_set_meta_integer (view->item, "delay", MIDORI_DELAY_UNDELAYED);
+
     /* Remove link labels */
     js_context = webkit_web_frame_get_global_context (web_frame);
     result = sokoke_js_script_eval (js_context,
@@ -4205,7 +4208,7 @@
             katze_assign (view->uri, NULL);
             katze_assign (view->mime_type, NULL);
             katze_item_set_meta_string (view->item, "mime-type", NULL);
-            katze_item_set_meta_integer (view->item, "delay", -1);
+            katze_item_set_meta_integer (view->item, "delay", MIDORI_DELAY_UNDELAYED);
 
             html = midori_speed_dial_get_html (dial, NULL);
             midori_view_load_alternate_string (view, html, "about:blank", NULL);
@@ -4365,10 +4368,12 @@
                 gchar const* version_strings[] = {
                     LIBSOUP_VERSION,
                     CAIRO_VERSION_STRING, cairo_version_string (),
+                    #ifdef HAVE_GCR
                     GCR_VERSION,
+                    #elif HAVE_GRANITE
                     GRANITE_VERSION,
                     LIBNOTIFY_VERSION,
-                    #ifdef HAVE_HILDON_2_2
+                    #elif HAVE_HILDON_2_2
                     "Hildon 2.2",
                     #elif HAVE_HILDON
                     "Hildon",
@@ -4437,15 +4442,15 @@
             webkit_web_view_load_html_string (
                 WEBKIT_WEB_VIEW (view->web_view), data, view->uri);
             g_free (data);
-            katze_item_set_meta_integer (view->item, "delay", -1);
+            katze_item_set_meta_integer (view->item, "delay", MIDORI_DELAY_UNDELAYED);
             if (g_strcmp0 (view->item->uri, view->uri))
                 katze_item_set_uri (view->item, view->uri);
             g_object_notify (G_OBJECT (view), "uri");
         }
-        else if (katze_item_get_meta_boolean (view->item, "delay"))
+        else if (katze_item_get_meta_integer (view->item, "delay") == MIDORI_DELAY_DELAYED)
         {
             katze_assign (view->uri, g_strdup (uri));
-            katze_item_set_meta_integer (view->item, "delay", -2);
+            katze_item_set_meta_integer (view->item, "delay", MIDORI_DELAY_PENDING_UNDELAY);
             midori_view_display_error (
                 view, view->uri, view->title ? view->title : view->uri,
                 _("Page loading delayed"),
@@ -5479,7 +5484,6 @@
         webkit_web_view_reload (WEBKIT_WEB_VIEW (view->web_view));
     else
         webkit_web_view_reload_bypass_cache (WEBKIT_WEB_VIEW (view->web_view));
-    katze_item_set_meta_integer (view->item, "delay", -1);
 }
 
 /**
