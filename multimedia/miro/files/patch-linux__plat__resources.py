--- ./linux/plat/resources.py.orig	2011-05-25 00:30:12.000000000 +0200
+++ ./linux/plat/resources.py	2011-05-25 17:53:57.000000000 +0200
@@ -45,9 +45,9 @@
 import platform
 
 RESOURCE_ROOT = os.path.abspath(
-    os.environ.get('MIRO_RESOURCE_ROOT', '/usr/share/miro/resources/'))
+    os.environ.get('MIRO_RESOURCE_ROOT', '%%PREFIX%%/share/miro/resources/'))
 SHARE_ROOT = os.path.abspath(
-    os.environ.get('MIRO_SHARE_ROOT', '/usr/share/'))
+    os.environ.get('MIRO_SHARE_ROOT', '%%PREFIX%%/share'))
 
 
 def root():
@@ -81,7 +81,7 @@
 
 
 def theme_path(theme, relative_path):
-    return os.path.join('/usr/share/miro/themes', theme, relative_path)
+    return os.path.join('%%PREFIX%%/share/miro/themes', theme, relative_path)
 
 
 def check_kde():
