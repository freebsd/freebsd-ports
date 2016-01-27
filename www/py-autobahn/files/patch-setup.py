--- setup.py.orig	2016-01-24 16:10:22 UTC
+++ setup.py
@@ -32,12 +32,9 @@ import platform
 from setuptools import setup
 from setuptools.command.test import test as test_command
 
-# remember if we already had six _before_ installation
-try:
-    import six  # noqa
-    _HAD_SIX = True
-except ImportError:
-    _HAD_SIX = False
+# We don't want this package to regenerate the Twisted dropin.cache
+# as it creates a filesystem violation by writing outside of STAGEDIR
+_HAD_SIX = False
 
 CPY = platform.python_implementation() == 'CPython'
 PY3 = sys.version_info >= (3,)
