--- setup.py.orig	2015-07-07 10:35:56 UTC
+++ setup.py
@@ -32,6 +32,8 @@ See ``AUTHORS`` for a full list of contr
 """
 
 from setuptools import setup, find_packages
+from setuptools.command.test import test as TestCommand
+import sys
 from sys import version_info
 
 import turses
@@ -40,13 +42,31 @@ NAME = "turses"
 
 REQUIREMENTS = [
     "urwid",
-    "tweepy==3.1.0",
+    "tweepy>=3.1.0",
 ]
 if version_info[:2] == (2, 6):
     REQUIREMENTS.append("argparse")
 
 TEST_REQUIREMENTS = list(REQUIREMENTS)
-TEST_REQUIREMENTS.extend(["mock", "pytest", "coverage", "tox"])
+TEST_REQUIREMENTS.extend(["mock", "pytest"])
+
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
 
 try:
     long_description = open("README.rst").read() + "\n\n" + open(
@@ -80,4 +100,6 @@ setup(name=NAME,
           "Topic :: Communications",
       ],
       install_requires=REQUIREMENTS,
-      tests_require=TEST_REQUIREMENTS)
+      tests_require=TEST_REQUIREMENTS,
+      cmdclass = {'test': PyTest},
+)
