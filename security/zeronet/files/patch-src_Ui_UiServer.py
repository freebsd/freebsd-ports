--- src/Ui/UiServer.py.orig	2019-09-04 18:16:57 UTC
+++ src/Ui/UiServer.py
@@ -133,7 +133,7 @@ class UiServer:
                 from werkzeug.debug import DebuggedApplication
                 handler = DebuggedApplication(self.handleRequest, evalex=True)
             except Exception as err:
-                self.log.info("%s: For debugging please download Werkzeug (http://werkzeug.pocoo.org/)" % err)
+                self.log.info("%s: For debugging please enable the port option: DEBUG=on" % err)
                 from Debug import DebugReloader
         self.log.write = lambda msg: self.log.debug(msg.strip())  # For Wsgi access.log
         self.log.info("--------------------------------------")
@@ -192,7 +192,7 @@ class UiServer:
 
         self.server.socket.close()
         self.server.stop()
-        self.running = False
+        time.sleep(1)
         time.sleep(1)
 
     def updateWebsocket(self, **kwargs):
