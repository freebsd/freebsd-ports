--- butterfly.server.py.orig	2017-02-10 00:08:34 UTC
+++ butterfly.server.py
@@ -20,7 +20,7 @@
 import tornado.options
 import tornado.ioloop
 import tornado.httpserver
-import tornado_systemd
+#import tornado_systemd
 import logging
 import webbrowser
 import uuid
@@ -295,13 +295,13 @@ else:
 from butterfly import application
 application.butterfly_dir = butterfly_dir
 log.info('Starting server')
-http_server = tornado_systemd.SystemdHTTPServer(
+http_server = tornado.httpserver.HTTPServer(
     application, ssl_options=ssl_opts)
 http_server.listen(port, address=host)
 
-if http_server.systemd:
-    os.environ.pop('LISTEN_PID')
-    os.environ.pop('LISTEN_FDS')
+#if http_server.systemd:
+#    os.environ.pop('LISTEN_PID')
+#    os.environ.pop('LISTEN_FDS')
 
 log.info('Starting loop')
 
