--- setup.py.orig	2019-01-13 14:15:14 UTC
+++ setup.py
@@ -5,14 +5,15 @@ import re
 import os
 import sys
 
+from io import open
+
 from setuptools import setup, find_packages
 from setuptools.command.test import test as TestCommand
 
 here = os.path.abspath(os.path.dirname(__file__))
-README = open(os.path.join(here, 'README.md')).read()
-CHANGES = open(os.path.join(here, 'CHANGES.rst')).read()
+README = open(os.path.join(here, 'README.md'), encoding='utf-8').read()
+CHANGES = open(os.path.join(here, 'CHANGES.rst'), encoding='utf-8').read()
 
-
 class PyTest(TestCommand):
     user_options = [('pytest-args=', 'a', "Arguments to pass into py.test")]
 
@@ -43,8 +44,10 @@ with open(os.path.join(here, 'gandi', 'cli', '__init__
 
 requires = ['setuptools', 'pyyaml', 'click>=7.0', 'requests', 'IPy']
 
-tests_require = ['pytest', 'pytest-cov', 'tox']
+tests_require = ['pytest']
 
+dev_requires = ['pytest-cov', 'tox']
+
 if sys.version_info < (3, 0):
     tests_require += ['mock']
 else:
@@ -54,7 +57,7 @@ else:
             " (sys.version: {})".format(sys.version))
 
 extras_require = {
-    'test': tests_require,
+    'dev': dev_requires,
 }
 
 setup(name='gandi.cli',
