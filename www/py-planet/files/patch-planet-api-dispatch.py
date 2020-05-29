--- planet/api/dispatch.py.orig	2020-01-13 22:11:38 UTC
+++ planet/api/dispatch.py
@@ -149,7 +149,7 @@ class RequestsDispatcher(object):
 
     def _dispatch_async(self, request, callback):
         return _do_request(self._asyncpool, request, stream=True,
-                           background_callback=callback)
+                           hooks=callback)
 
     def _dispatch(self, request, callback=None):
         return _do_request(self.session, request)
