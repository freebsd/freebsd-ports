--- spyne/test/transport/test_msgpack.py.orig	2014-06-09 22:35:04 UTC
+++ spyne/test/transport/test_msgpack.py
@@ -52,9 +52,9 @@ class TestMessagePackServer(unittest.Tes
         request = msgpack.packb({'yay': [v]})
         prot.dataReceived(msgpack.packb([1, request]))
         val = prot.transport.value()
-        print repr(val)
+        print(repr(val))
         val = msgpack.unpackb(val)
-        print repr(val)
+        print(repr(val))
 
         self.assertEquals(val, {0: msgpack.packb(v)})
 
@@ -80,9 +80,9 @@ class TestMessagePackServer(unittest.Tes
         request = msgpack.packb({'yay': [v]})
         def _ccb(_):
             val = prot.transport.value()
-            print repr(val)
+            print(repr(val))
             val = msgpack.unpackb(val)
-            print repr(val)
+            print(repr(val))
 
             self.assertEquals(val, {0: msgpack.packb(v)})
 
