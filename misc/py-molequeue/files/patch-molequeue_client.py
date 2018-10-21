--- molequeue/client.py.orig	2018-10-21 03:22:34 UTC
+++ molequeue/client.py
@@ -122,7 +122,7 @@ class Client:
     self.socket = self.context.socket(zmq.DEALER)
 
     tmpdir = tempfile.gettempdir()
-    connection_string  = 'ipc://%s/%s_%s' %  (tmpdir, 'zmq', server)
+    connection_string  = 'ipc://%s/%s' %  (tmpdir, server)
     self.socket.connect(connection_string)
 
     io_loop = ioloop.IOLoop.instance()
