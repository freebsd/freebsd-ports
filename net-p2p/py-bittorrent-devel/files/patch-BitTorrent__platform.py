--- ./BitTorrent/platform.py.orig	Mon Jun 12 22:46:01 2006
+++ ./BitTorrent/platform.py	Wed Jun 21 23:57:08 2006
@@ -131,7 +131,7 @@
 
 
 def calc_unix_dirs():
-    appdir = '%s-%s'%(app_name, version)
+    appdir = '%s'%(app_name)
     ip = os.path.join('share', 'pixmaps', appdir)
     dp = os.path.join('share', 'doc'    , appdir)
     lp = os.path.join('share', 'locale')
