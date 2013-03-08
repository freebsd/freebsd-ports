--- ./extensions/external-download-manager.vala.orig	2013-03-07 17:44:14.000000000 +0000
+++ ./extensions/external-download-manager.vala	2013-03-07 23:04:44.000000000 +0000
@@ -137,18 +137,34 @@
 #if !HAVE_WIN32
     private class Aria2 : ExternalDownloadManager {
         public override bool download (DownloadRequest dlReq) {
+#if !HAVE_GLIB_2_30
+            var url = new GLib.ValueArray (2);
+            var uri = new GLib.Value (typeof (string));
+            uri.set_string (dlReq.uri);
+            url.insert (0, uri);
+#else
             var url = value_array_new ();
             value_array_insert (url, 0, typeof (string), dlReq.uri);
+#endif
 
             GLib.HashTable<string, GLib.Value?> options = value_hash_new ();
             var referer = new GLib.Value (typeof (string));
             referer.set_string (dlReq.referer);
             options.insert ("referer", referer);
 
+#if !HAVE_GLIB_2_30
+            var headers = new GLib.ValueArray (2);
+            if (dlReq.cookie_header != null) {
+                var cookie = new GLib.Value (typeof (string));
+                cookie.set_string ("Cookie: %s".printf(dlReq.cookie_header));
+                headers.insert (0, cookie);
+            }
+#else
             var headers = value_array_new ();
             if (dlReq.cookie_header != null) {
                 value_array_insert (headers, 0, typeof (string), "Cookie: %s".printf(dlReq.cookie_header));
             }
+#endif
 
             if (headers.n_values > 0)
                options.insert ("header", headers);
@@ -161,8 +177,13 @@
             session.send_message (message);
 
             try {
+#if !HAVE_GLIB_2_30
+                var v = new GLib.Value (typeof (string));
+                XMLRPC.parse_method_response ((string) message.response_body.flatten ().data, -1, v);
+#else
                 Value v;
                 XMLRPC.parse_method_response ((string) message.response_body.flatten ().data, -1, out v);
+#endif
                 return true;
             } catch (Error e) {
                 this.handle_exception (e);
