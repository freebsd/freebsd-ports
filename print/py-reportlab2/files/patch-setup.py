--- setup.py.orig	Tue May 23 15:56:46 2006
+++ setup.py	Sat Dec 30 18:43:39 2006
@@ -19,7 +19,7 @@
 isfile = os.path.isfile
 isdir = os.path.isfile
 dirname = os.path.dirname
-package_path = pjoin(package_home(distutils.__dict__), 'site-packages', 'reportlab')
+package_path = os.environ['PACKAGE_PATH']
 
 def get_version():
     #determine Version
@@ -235,6 +235,7 @@
             packages=[ # include anything with an __init__
                     'reportlab',
                     'reportlab.extensions',
+                    'reportlab.graphics.barcode',
                     'reportlab.graphics.charts',
                     'reportlab.graphics.samples',
                     'reportlab.graphics.widgets',
