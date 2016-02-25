--- setup.py.orig	2016-02-21 16:49:18 UTC
+++ setup.py
@@ -1,17 +1,19 @@
-from setuptools import setup
+from setuptools import setup, find_packages
 from setuptools.command.test import test as TestCommand
 import sys
 
 
 class PyTest(TestCommand):
-    def finalize_options(self):
-        TestCommand.finalize_options(self)
-        self.test_args = []
-        self.test_suite = True
+    user_options = [('pytest-args=', 'a', "Arguments to pass to py.test")]
+
+    def initialize_options(self):
+        TestCommand.initialize_options(self)
+        self.pytest_args = []
 
     def run_tests(self):
+        #import here, cause outside the eggs aren't loaded
         import pytest
-        errno = pytest.main(self.test_args)
+        errno = pytest.main(self.pytest_args)
         sys.exit(errno)
 
 
@@ -31,12 +33,12 @@ setup(
         'https://s3.amazonaws.com/bitly-downloads/nsq/pynsq-%s.tar.gz' %
         version
     ),
-    packages=['nsq'],
     install_requires=['tornado'],
     include_package_data=True,
+    packages=find_packages(exclude=['tests']),
     zip_safe=False,
     tests_require=['pytest', 'mock', 'simplejson',
-                   'python-snappy', 'tornado'],
+                   'python-snappy'],
     cmdclass={'test': PyTest},
     classifiers=[
         'Development Status :: 4 - Beta',
