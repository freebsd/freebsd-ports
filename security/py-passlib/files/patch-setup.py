--- ./setup.py.orig	2012-06-11 20:52:21.000000000 +1000
+++ ./setup.py	2012-06-11 20:52:35.000000000 +1000
@@ -15,12 +15,8 @@
 
 py3k = (sys.version_info[0] >= 3)
 
-try:
-    from setuptools import setup
-    has_distribute = True
-except ImportError:
-    from distutils.core import setup
-    has_distribute = False
+from distutils.core import setup
+has_distribute = False
 
 #=========================================================
 # init setup options
