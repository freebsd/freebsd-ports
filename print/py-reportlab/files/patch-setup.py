--- setup.py.orig	Tue Apr 15 16:52:36 2003
+++ setup.py	Sun Sep 28 02:10:42 2003
@@ -18,7 +18,7 @@
 
 pjoin = os.path.join
 
-package_path = pjoin(package_home(distutils.__dict__), 'reportlab')
+package_path = os.environ['PACKAGE_PATH']
 
 
 # why oh why don't most setup scripts have a script handler?
