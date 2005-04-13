--- server/simple_server.py.orig	Tue Apr  5 21:38:19 2005
+++ server/simple_server.py	Wed Apr 13 15:24:07 2005
@@ -72,7 +72,7 @@
     """Runs a simple, single threaded, synchronous HTTP server that
     publishes a Quixote application.
     """
-    if HTTPS:
+    if https:
         HTTPRequestHandler.required_cgi_environment['HTTPS'] = 'on'
     httpd = HTTPServer((host, port), HTTPRequestHandler)
     publisher = create_publisher()
