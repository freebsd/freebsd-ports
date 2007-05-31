--- ./BitTorrent/platform.py.orig	Mon May  7 05:42:18 2007
+++ ./BitTorrent/platform.py	Mon May  7 05:42:46 2007
@@ -289,7 +289,7 @@
             osx = True
 
 def calc_unix_dirs():
-    appdir = '%s-%s' % (app_name, version)
+    appdir = '%s' % (app_name)
     ip = os.path.join(efs2(u'share'), efs2(u'pixmaps'), appdir)
     dp = os.path.join(efs2(u'share'), efs2(u'doc'), appdir)
     lp = os.path.join(efs2(u'share'), efs2(u'locale'))
