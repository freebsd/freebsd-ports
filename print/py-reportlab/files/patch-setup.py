--- setup.py.orig	Thu Jan 22 01:45:46 2004
+++ setup.py	Mon Jan 26 11:59:58 2004
@@ -17,7 +17,7 @@
     return r
 
 pjoin = os.path.join
-package_path = pjoin(package_home(distutils.__dict__), 'reportlab')
+package_path = os.environ['PACKAGE_PATH']
 
 def get_version():
     #determine Version
