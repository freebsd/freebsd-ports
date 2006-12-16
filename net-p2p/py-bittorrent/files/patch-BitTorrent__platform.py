--- BitTorrent/platform.py.orig	Tue Oct 10 19:23:41 2006
+++ BitTorrent/platform.py	Sat Dec 16 08:32:18 2006
@@ -281,7 +281,7 @@
             osx = True
 
 def calc_unix_dirs():
-    appdir = '%s-%s' % (app_name, version)
+    appdir = '%s' % (app_name)
     ip = os.path.join(efs2(u'share'), efs2(u'pixmaps'), appdir)
     dp = os.path.join(efs2(u'share'), efs2(u'doc'), appdir)
     lp = os.path.join(efs2(u'share'), efs2(u'locale'))
