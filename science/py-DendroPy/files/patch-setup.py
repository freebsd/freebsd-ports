--- setup.py.orig	2010-01-09 13:22:53.000000000 +0800
+++ setup.py	2010-01-09 13:23:15.000000000 +0800
@@ -28,9 +28,9 @@
 import os
 
 try:
-    import ez_setup
-    sys.stderr.write("using ez_setup ('%s')\n" % os.path.abspath(ez_setup.__file__))
-    ez_setup.use_setuptools()
+#    import ez_setup
+#    sys.stderr.write("using ez_setup ('%s')\n" % os.path.abspath(ez_setup.__file__))
+#    ez_setup.use_setuptools()
     import setuptools
     sys.stderr.write("using setuptools ('%s')\n" % os.path.abspath(setuptools.__file__))
     from setuptools import setup, find_packages
