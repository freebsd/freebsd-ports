--- flup/server/ajp_base.py.orig	2017-12-16 07:40:39 UTC
+++ flup/server/ajp_base.py
@@ -38,7 +38,11 @@ import datetime
 import time
 
 # Unfortunately, for now, threads are required.
-import thread
+try:
+    import thread
+except:
+    import _thread as thread
+
 import threading
 
 __all__ = ['BaseAJPServer']
