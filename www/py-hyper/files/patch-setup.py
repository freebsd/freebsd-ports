--- setup.py.orig	2015-10-28 10:21:14 UTC
+++ setup.py
@@ -7,6 +7,7 @@ import sys
 
 try:
     from setuptools import setup
+    from setuptools.command.test import test as TestCommand
 except ImportError:
     from distutils.core import setup
 
@@ -48,6 +49,24 @@ def resolve_install_requires():
         return deps
     return []
 
+class PyTest(TestCommand):
+    user_options = [('pytest-args=', 'a', "Arguments to pass to py.test")]
+
+    def initialize_options(self):
+        TestCommand.initialize_options(self)
+        self.pytest_args = []
+
+    def finalize_options(self):
+        TestCommand.finalize_options(self)
+        self.test_args = []
+        self.test_suite = True
+
+    def run_tests(self):
+        #import here, cause outside the eggs aren't loaded
+        import pytest
+        errno = pytest.main(self.pytest_args)
+        sys.exit(errno)
+
 packages = [
     'hyper',
     'hyper.http20',
@@ -90,5 +109,7 @@ setup(
     },
     extras_require={
         'fast': ['pycohttpparser'],
-    }
+    },
+    tests_require=['pytest'],
+    cmdclass = {'test': PyTest},
 )
