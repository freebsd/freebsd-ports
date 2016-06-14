--- src/Ui/UiServer.py.orig	2016-06-11 08:29:47 UTC
+++ src/Ui/UiServer.py
@@ -107,7 +107,7 @@ class UiServer:
                 from werkzeug.debug import DebuggedApplication
                 handler = DebuggedApplication(self.handleRequest, evalex=True)
             except Exception, err:
-                self.log.info("%s: For debugging please download Werkzeug (http://werkzeug.pocoo.org/)" % err)
+                self.log.info("%s: For debugging please enable the port option: DEBUG=on" % err)
                 from Debug import DebugReloader
         self.log.write = lambda msg: self.log.debug(msg.strip())  # For Wsgi access.log
         self.log.info("--------------------------------------")
@@ -155,4 +155,4 @@ class UiServer:
 
         self.server.socket.close()
         self.server.stop()
-        time.sleep(1)
\ No newline at end of file
+        time.sleep(1)
