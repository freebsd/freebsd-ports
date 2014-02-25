--- setup.py.orig	Fri Nov 26 00:12:20 2004
+++ setup.py	Mon Mar 21 03:26:45 2005
@@ -19,7 +19,7 @@
 isfile = os.path.isfile
 isdir = os.path.isfile
 dirname = os.path.dirname
-package_path = pjoin(package_home(distutils.__dict__), 'site-packages', 'reportlab')
+package_path = os.environ['PACKAGE_PATH']
 
 def get_version():
     #determine Version
