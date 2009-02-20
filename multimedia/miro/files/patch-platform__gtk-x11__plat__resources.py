--- platform/gtk-x11/plat/resources.py.orig	2009-02-12 06:37:07.000000000 +0900
+++ platform/gtk-x11/plat/resources.py	2009-02-13 01:56:28.000000000 +0900
@@ -29,10 +29,10 @@
 import os
 import urllib
 
-resource_root = os.environ.get('MIRO_RESOURCE_ROOT', '/usr/share/miro/resources/')
+resource_root = os.environ.get('MIRO_RESOURCE_ROOT', '%%PREFIX%%/share/miro/resources/')
 resource_root = os.path.abspath(resource_root)
 
-share_root = os.environ.get('MIRO_SHARE_ROOT', '/usr/share/')
+share_root = os.environ.get('MIRO_SHARE_ROOT', '%%PREFIX%%/share/')
 share_root = os.path.abspath(share_root)
 
 # Note: some of these functions are probably not absolutely correct in
@@ -63,7 +63,7 @@
     return u"file://%s" % urllib.quote(absolute_path)
 
 def theme_path(theme, relative_path):
-    return os.path.join('/usr/share/miro/themes', theme, relative_path)
+    return os.path.join('%%PREFIX%%/share/miro/themes', theme, relative_path)
 
 def check_kde():
     return os.environ.get("KDE_FULL_SESSION", None) != None
