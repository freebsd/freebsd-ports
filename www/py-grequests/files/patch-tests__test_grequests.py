# Fix: request use **kwargs with its hooks.
# https://github.com/kennethreitz/grequests/commit/f50782ad63607b85e5e009f4a0a4ce0a8a6aef0d

--- ./tests/test_grequests.py.orig	2014-02-16 17:23:40.926364751 +1100
+++ ./tests/test_grequests.py	2014-02-16 17:24:14.491232949 +1100
@@ -38,7 +38,7 @@
     def test_hooks(self):
         result = {}
 
-        def hook(r):
+        def hook(r, **kwargs):
             result[r.url] = True
             return r
 
@@ -49,7 +49,7 @@
     def test_callback_kwarg(self):
         result = {'ok': False}
 
-        def callback(r):
+        def callback(r, **kwargs):
             result['ok'] = True
             return r
 
