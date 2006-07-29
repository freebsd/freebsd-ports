--- ./BitTorrent/platform.py.orig	Wed Jul 12 02:18:37 2006
+++ ./BitTorrent/platform.py	Sat Jul 22 17:42:24 2006
@@ -334,7 +334,7 @@
 
 
 def calc_unix_dirs():
-    appdir = '%s-%s'%(app_name, version)
+    appdir = '%s'%(app_name)
     ip = os.path.join(efs(u'share')[0], efs(u'pixmaps')[0], appdir)
     dp = os.path.join(efs(u'share')[0], efs(u'doc')[0], appdir)
     lp = os.path.join(efs(u'share')[0], efs(u'locale')[0])
