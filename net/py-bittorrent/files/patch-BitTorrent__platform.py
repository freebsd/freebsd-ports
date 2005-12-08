--- BitTorrent/platform.py.orig	Mon Aug 15 20:06:05 2005
+++ BitTorrent/platform.py	Wed Aug 24 00:12:59 2005
@@ -41,7 +41,7 @@
     del wh, wv
 
 def calc_unix_dirs():
-    appdir = '%s-%s'%(app_name, version)
+    appdir = '%s'%(app_name)
     ip = os.path.join('share', 'pixmaps', appdir)
     dp = os.path.join('share', 'doc'    , appdir)
     lp = os.path.join('share', 'locale')
