--- msrplib/connect.py.orig	2011-06-03 22:32:33.000000000 +0700
+++ msrplib/connect.py	2011-07-16 22:36:33.000000000 +0700
@@ -48,7 +48,7 @@
 from application.python import Null
 from application.system import host
 from eventlet.twistedutil.protocol import GreenClientCreator, SpawnFactory
-from eventlet import coros
+from eventlet import coros, event
 from eventlet.api import timeout, sleep
 from eventlet.green.socket import gethostbyname
 
@@ -238,7 +238,7 @@
         """
         if local_uri is None:
             local_uri = self.generate_local_uri()
-        self.transport_event = coros.event()
+        self.transport_event = event.Event()
         local_uri.host = gethostbyname(local_uri.host)
         factory = SpawnFactory(self.transport_event, MSRPTransport, local_uri, logger=self.logger, use_sessmatch=self.use_sessmatch)
         self.listening_port = self._listen(local_uri, factory)
@@ -357,17 +357,17 @@
             self.msrp = None
 
 
-class Notifier(coros.event):
+class Notifier(event.Event):
 
     def wait(self):
         if self.ready():
             self.reset()
-        return coros.event.wait(self)
+        return event.Event.wait(self)
 
     def send(self, value=None, exc=None):
         if self.ready():
             self.reset()
-        return coros.event.send(self, value, exc=exc)
+        return event.Event.send(self, value, exc=exc)
 
 
 class MSRPServer(ConnectBase):
@@ -473,7 +473,7 @@
         If no such binding was made within MSRPBindSessionTimeout.seconds, raise MSRPBindSessionTimeout.
         """
         full_remote_path = tuple(full_remote_path)
-        event = coros.event()
+        event = event.Event()
         self.expected_remote_paths[full_remote_path] = event
         try:
             self.new_full_remote_path_notifier.send()
