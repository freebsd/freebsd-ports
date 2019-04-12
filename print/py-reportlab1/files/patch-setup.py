--- setup.py.orig	2007-07-20 10:36:08 UTC
+++ setup.py
@@ -19,7 +19,7 @@ abspath = os.path.abspath
 isfile = os.path.isfile
 isdir = os.path.isfile
 dirname = os.path.dirname
-package_path = pjoin(package_home(distutils.__dict__), 'site-packages', 'reportlab')
+package_path = os.environ['PACKAGE_PATH']
 
 def get_version():
     #determine Version
