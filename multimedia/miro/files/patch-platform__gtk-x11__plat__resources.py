--- platform/gtk-x11/plat/resources.py.orig	2009-07-25 12:41:11.000000000 +0900
+++ platform/gtk-x11/plat/resources.py	2009-07-30 15:48:04.000000000 +0900
@@ -44,8 +44,8 @@
 import platform
 
 resource_root = os.path.abspath(os.environ.get('MIRO_RESOURCE_ROOT',
-                                               '/usr/share/miro/resources/'))
-share_root = os.path.abspath(os.environ.get('MIRO_SHARE_ROOT', '/usr/share/'))
+                                               '%%PREFIX%%/share/miro/resources/'))
+share_root = os.path.abspath(os.environ.get('MIRO_SHARE_ROOT', '%%PREFIX%%/share/'))
 
 def root():
     return resource_root
@@ -71,7 +71,7 @@
     return u"file://%s" % urllib.quote(absolute_path)
 
 def theme_path(theme, relative_path):
-    return os.path.join('/usr/share/miro/themes', theme, relative_path)
+    return os.path.join('%%PREFIX%%/share/miro/themes', theme, relative_path)
 
 def check_kde():
     return os.environ.get("KDE_FULL_SESSION", None) != None
