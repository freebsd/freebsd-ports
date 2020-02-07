--- cts/remote.py.orig	2020-02-07 14:06:22 UTC
+++ cts/remote.py
@@ -125,7 +125,7 @@ class RemoteExec:
     '''
 
     def __init__(self, rsh, silent=False):
-        self.async = []
+        self.async_calls = []
         self.rsh = rsh
         self.silent = silent
         self.logger = LogFactory()
