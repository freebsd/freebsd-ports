--- spyne/test/transport/test_msgpack.py.orig	2016-10-28 11:15:20 UTC
+++ spyne/test/transport/test_msgpack.py
@@ -54,9 +54,9 @@ class TestMessagePackServer(unittest.Tes
         request = msgpack.packb({'yay': [v]})
         prot.dataReceived(msgpack.packb([1, request]))
         val = prot.transport.value()
-        print repr(val)
+        print(repr(val))
         val = msgpack.unpackb(val)
-        print repr(val)
+        print(repr(val))
 
         self.assertEquals(val, [0, msgpack.packb(v)])
 
@@ -82,9 +82,9 @@ class TestMessagePackServer(unittest.Tes
         request = msgpack.packb({'yay': [v]})
         def _ccb(_):
             val = prot.transport.value()
-            print repr(val)
+            print(repr(val))
             val = msgpack.unpackb(val)
-            print repr(val)
+            print(repr(val))
 
             self.assertEquals(val, [0, msgpack.packb(v)])
 
