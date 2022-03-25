--- tornado/test/asyncio_test.py.orig	2018-01-05 03:07:44 UTC
+++ tornado/test/asyncio_test.py
@@ -46,7 +46,8 @@ class AsyncIOLoopTest(AsyncTestCase):
         if hasattr(asyncio, 'ensure_future'):
             ensure_future = asyncio.ensure_future
         else:
-            ensure_future = asyncio.async
+            # async is a reserved word in Python 3.7
+            ensure_future = getattr(asyncio, "async")
 
         x = yield ensure_future(
             asyncio.get_event_loop().run_in_executor(None, lambda: 42))
