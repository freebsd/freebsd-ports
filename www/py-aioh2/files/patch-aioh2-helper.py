--- aioh2/helper.py.orig	2018-02-05 02:31:19 UTC
+++ aioh2/helper.py
@@ -86,4 +86,4 @@ if hasattr(socket, 'AF_UNIX'):
 if hasattr(asyncio, 'ensure_future'):  # Python >= 3.5
     async_task = asyncio.ensure_future
 else:
-    async_task = asyncio.async
+    async_task = getattr(asyncio, "async")
