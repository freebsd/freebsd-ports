--- ./setup.py.orig	2013-08-14 18:16:13.000000000 +0900
+++ ./setup.py	2013-08-14 18:16:39.000000000 +0900
@@ -4,11 +4,7 @@
 
 from beaver import __version__
 
-try:
-    from setuptools import setup
-    setup  # workaround for pyflakes issue #13
-except ImportError:
-    from distutils.core import setup
+from distutils.core import setup
 
 # Hack to prevent stupid TypeError: 'NoneType' object is not callable error on
 # exit of python setup.py test # in multiprocessing/util.py _exit_function when
