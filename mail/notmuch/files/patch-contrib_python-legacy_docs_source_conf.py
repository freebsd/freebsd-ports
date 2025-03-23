--- contrib/python-legacy/docs/source/conf.py.orig	2025-03-15 22:04:35 UTC
+++ contrib/python-legacy/docs/source/conf.py
@@ -13,7 +13,19 @@ import sys, os
 
 import sys, os
 
-from unittest.mock import Mock
+try:
+    from unittest.mock import Mock
+except ImportError:
+    class Mock(object):
+        def __init__(self, *args, **kwargs):
+            pass
+
+        def __call__(self, *args, **kwargs):
+            return Mock()
+
+        @classmethod
+        def __getattr__(self, name):
+            return Mock() if name not in ('__file__', '__path__') else '/dev/null'
 
 # If extensions (or modules to document with autodoc) are in another directory,
 # add these directories to sys.path here. If the directory is relative to the
