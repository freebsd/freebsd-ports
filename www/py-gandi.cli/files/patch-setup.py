--- setup.py.orig	2016-02-08 14:17:09 UTC
+++ setup.py
@@ -6,11 +6,11 @@ import os
 import sys
 
 from setuptools import setup, find_packages
+from io import open
 
 here = os.path.abspath(os.path.dirname(__file__))
-README = open(os.path.join(here, 'README.md')).read()
-CHANGES = open(os.path.join(here, 'CHANGES.rst')).read()
-
+README = open(os.path.join(here, 'README.md'), encoding='utf-8').read()
+CHANGES = open(os.path.join(here, 'CHANGES.rst'), encoding='utf-8').read()
 
 with open(os.path.join(here, 'gandi', 'cli', '__init__.py')) as v_file:
     version = re.compile(r".*__version__ = '(.*?)'",
@@ -18,7 +18,7 @@ with open(os.path.join(here, 'gandi', 'c
 
 requires = ['setuptools', 'pyyaml', 'click>=3.1', 'requests', 'IPy']
 
-tests_require = ['nose', 'coverage', 'tox', 'httpretty==0.8.6']
+tests_require = ['httpretty>=0.8.6']
 if sys.version_info < (2, 7):
     tests_require += ['unittest2', 'importlib']
 
@@ -54,7 +54,7 @@ setup(name='gandi.cli',
     zip_safe=False,
     install_requires=requires,
     tests_require=tests_require,
-    test_suite='nose.collector',
+    test_suite='gandi.cli.tests',
     extras_require=extras_require,
     entry_points={
         'console_scripts': [
