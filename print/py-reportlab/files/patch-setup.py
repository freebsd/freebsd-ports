--- setup.py.orig	Mon Dec 23 08:03:38 2002
+++ setup.py	Mon Mar  3 16:00:37 2003
@@ -18,7 +18,7 @@
 
 pjoin = os.path.join
 
-package_path = pjoin(package_home(distutils.__dict__), 'reportlab')
+package_path = os.environ['PACKAGE_PATH']
 print package_path
 
 
