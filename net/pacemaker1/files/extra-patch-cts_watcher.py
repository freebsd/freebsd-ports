--- cts/watcher.py.orig	2020-02-07 14:06:26 UTC
+++ cts/watcher.py
@@ -140,8 +140,8 @@ class SearchObj:
         self.logger.debug(message)
 
     def harvest(self, delegate=None):
-        async = self.harvest_async(delegate)
-        async.join()
+        async_calls = self.harvest_async(delegate)
+        async_calls.join()
 
     def harvest_async(self, delegate=None):
         self.log("Not implemented")
