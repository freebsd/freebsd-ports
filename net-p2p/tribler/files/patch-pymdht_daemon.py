--- ../usr/share/tribler/Tribler/Core/DecentralizedTracking/pymdht/pymdht_daemon.py.orig	2012-02-08 00:33:48.000000000 +0900
+++ ../usr/share/tribler/Tribler/Core/DecentralizedTracking/pymdht/pymdht_daemon.py	2012-02-24 18:44:52.000000000 +0900
@@ -155,10 +155,10 @@
             raise SanitizeError, '? Channel must be a number'
     
     def handle(self):
+        global stop_server
         while not stop_server:
             line = self.rfile.readline().strip().upper()
             if line == 'KILL':
-                global stop_server
                 stop_server = True
                 return
             if line == 'EXIT':
