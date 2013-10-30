--- ./pavement.py.orig	2013-08-30 15:00:07.469952201 +0300
+++ ./pavement.py	2013-08-30 15:00:24.309518177 +0300
@@ -9,7 +9,7 @@
 try:
     from pydap.lib import __version__
 except ImportError:
-    __version__ = ('unknown',)
+    __version__ = ('3.1',)
 
 options = environment.options
 setup(**setup_meta)
