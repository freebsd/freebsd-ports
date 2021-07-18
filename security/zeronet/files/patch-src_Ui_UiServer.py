- replace the deprecated function cgi.parse_qsl -> urllib.parse.parse_qsl
- alter message about debugging

--- src/Ui/UiServer.py.orig	2019-09-04 18:16:57 UTC
+++ src/Ui/UiServer.py
@@ -4,6 +4,7 @@ import cgi
 import socket
 import sys
 import gevent
+import urllib
 
 from gevent.pywsgi import WSGIServer
 from gevent.pywsgi import WSGIHandler
@@ -95,7 +96,7 @@ class UiServer:
     def handleRequest(self, env, start_response):
         path = bytes(env["PATH_INFO"], "raw-unicode-escape").decode("utf8")
         if env.get("QUERY_STRING"):
-            get = dict(cgi.parse_qsl(env['QUERY_STRING']))
+            get = dict(urllib.parse.parse_qsl(env['QUERY_STRING']))
         else:
             get = {}
         ui_request = UiRequest(self, get, env, start_response)
@@ -133,7 +134,7 @@ class UiServer:
                 from werkzeug.debug import DebuggedApplication
                 handler = DebuggedApplication(self.handleRequest, evalex=True)
             except Exception as err:
-                self.log.info("%s: For debugging please download Werkzeug (http://werkzeug.pocoo.org/)" % err)
+                self.log.info("%s: For debugging please enable the port option: DEBUG=on" % err)
                 from Debug import DebugReloader
         self.log.write = lambda msg: self.log.debug(msg.strip())  # For Wsgi access.log
         self.log.info("--------------------------------------")
