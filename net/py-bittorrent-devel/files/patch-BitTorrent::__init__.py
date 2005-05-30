--- BitTorrent/__init__.py.orig	Fri Mar 11 22:53:12 2005
+++ BitTorrent/__init__.py	Fri Mar 11 22:53:27 2005
@@ -21,7 +21,7 @@
 import os
 
 def calc_unix_dirs():
-    appdir = '%s-%s'%(app_name, version)
+    appdir = '%s'%(app_name)
     ip = os.path.join('share', 'pixmaps', appdir)
     dp = os.path.join('share', 'doc'    , appdir)
     return ip, dp
