--- ./extensions/external-download-manager.vala.orig	2012-09-19 21:17:43.000000000 +0000
+++ ./extensions/external-download-manager.vala	2012-09-21 16:54:03.000000000 +0000
@@ -134,17 +134,23 @@
 
     private class Aria2 : ExternalDownloadManager {
         public override bool download (DownloadRequest dlReq) {
-            var url = value_array_new ();
-            value_array_insert (url, 0, typeof (string), dlReq.uri);
+            var url = new GLib.ValueArray (2);
+
+            var uri = new GLib.Value (typeof (string));
+            uri.set_string (dlReq.uri);
+
+            url.insert (0, uri);
 
             GLib.HashTable<string, GLib.Value?> options = value_hash_new ();
             var referer = new GLib.Value (typeof (string));
             referer.set_string (dlReq.referer);
             options.insert ("referer", referer);
 
-            var headers = value_array_new ();
+            var headers = new GLib.ValueArray (2);
             if (dlReq.cookie_header != null) {
-                value_array_insert (headers, 0, typeof (string), "Cookie: %s".printf(dlReq.cookie_header));
+                var cookie = new GLib.Value (typeof (string)); 
+                cookie.set_string ("Cookie: %s".printf(dlReq.cookie_header));
+                headers.insert (0, cookie);
             }
 
             if (headers.n_values > 0)
@@ -158,8 +164,8 @@
             session.send_message (message);
 
             try {
-                Value v;
-                XMLRPC.parse_method_response ((string) message.response_body.flatten ().data, -1, out v);
+                var v = new GLib.Value (typeof(string));
+                XMLRPC.parse_method_response ((string) message.response_body.flatten ().data, -1, v);
                 return true;
             } catch (Error e) {
                 this.handle_exception (e);
@@ -293,7 +299,7 @@
                          authors: "André Stösel <andre@stoesel.de>",
                          key: "commandline");
 
-            this.install_string ("commandline", "wget --no-check-certificate --referer={REFERER} --header={COOKIES} {URL}");
+            this.install_string ("commandline", "fetch {URL}");
 
             this.activate.connect (activated);
             this.deactivate.connect (deactivated);
