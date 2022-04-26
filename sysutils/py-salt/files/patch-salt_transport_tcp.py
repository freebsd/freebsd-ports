--- salt/transport/tcp.py.orig	2022-03-29 19:46:48 UTC
+++ salt/transport/tcp.py
@@ -1561,7 +1561,7 @@ class PubServer(salt.ext.tornado.tcpserver.TCPServer):
     @salt.ext.tornado.gen.coroutine
     def publish_payload(self, package, _):
         log.debug("TCP PubServer sending payload: %s", package)
-        payload = self.pack_publish(package)
+        package = self.pack_publish(package)
         payload = salt.transport.frame.frame_msg(package["payload"])
 
         to_remove = []
