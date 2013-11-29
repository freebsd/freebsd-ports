--- ./pavement.py.orig	2013-11-15 10:29:56.254992996 +0200
+++ ./pavement.py	2013-11-15 10:31:41.824987045 +0200
@@ -9,7 +9,7 @@
 try:
     from pydap.lib import __version__
 except ImportError:
-    __version__ = ('unknown',)
+    __version__ = (3,1,1)
 
 options = environment.options
 setup(**setup_meta)
