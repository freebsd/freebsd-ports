--- aioh2/protocol.py.orig	2017-12-03 09:08:55 UTC
+++ aioh2/protocol.py
@@ -380,7 +380,7 @@ class H2Protocol(asyncio.Protocol):
         if self._handler:
             raise Exception('Handler was already set')
         if handler:
-            self._handler = asyncio.async(handler, loop=self._loop)
+            self._handler = async_task(handler, loop=self._loop)
 
     def close_connection(self):
         self._transport.close()
