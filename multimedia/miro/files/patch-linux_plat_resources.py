--- linux/plat/resources.py.orig	2010-10-24 14:34:46.000000000 +0200
+++ linux/plat/resources.py	2010-10-24 14:35:12.000000000 +0200
@@ -44,9 +44,9 @@
 import platform
 
 RESOURCE_ROOT = os.path.abspath(
-    os.environ.get('MIRO_RESOURCE_ROOT', '/usr/share/miro/resources/'))
+    os.environ.get('MIRO_RESOURCE_ROOT', '%%PREFIX%%/share/miro/resources/'))
 SHARE_ROOT = os.path.abspath(
-    os.environ.get('MIRO_SHARE_ROOT', '/usr/share/'))
+    os.environ.get('MIRO_SHARE_ROOT', '%%PREFIX%%/share/'))
 
 def root():
     return RESOURCE_ROOT
@@ -67,7 +67,7 @@
     return u'file://%s' % urllib.quote(path(relative_path))
 
 def theme_path(theme, relative_path):
-    return os.path.join('/usr/share/miro/themes', theme, relative_path)
+    return os.path.join('%%PREFIX%%/share/miro/themes', theme, relative_path)
 
 def check_kde():
     return os.environ.get("KDE_FULL_SESSION", None) != None
