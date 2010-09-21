--- src/gtk2/gui/guiOptions.ml.orig	2007-07-01 09:59:48.000000000 -0300
+++ src/gtk2/gui/guiOptions.ml	2010-09-21 00:37:03.000000000 -0300
@@ -166,6 +166,16 @@
     "Direct TCP connections to HTTP proxy (the proxy should support CONNECT)"
     bool_option false
 
+let gtk_connection_http_proxy_login = define_option current_section
+    ["gtk_connection_http_proxy_login"]
+    "HTTP proxy login (leave empty if proxy doesn't require authentication)"
+    string_option ""
+
+let gtk_connection_http_proxy_password = define_option current_section
+    ["gtk_connection_http_proxy_password"]
+    "HTTP proxy password"
+    string_option ""
+
 (* {Client} *)
 
 let gtk_client_login = define_option current_section
