--- setup.py.orig	2017-09-13 12:32:20 UTC
+++ setup.py
@@ -6,19 +6,19 @@ import os
 import sys
 
 from setuptools import setup, find_packages
+from io import open
 
 here = os.path.abspath(os.path.dirname(__file__))
-README = open(os.path.join(here, 'README.md')).read()
-CHANGES = open(os.path.join(here, 'CHANGES.rst')).read()
+README = open(os.path.join(here, 'README.md'), encoding='utf-8').read()
+CHANGES = open(os.path.join(here, 'CHANGES.rst'), encoding='utf-8').read()
 
-
 with open(os.path.join(here, 'gandi', 'cli', '__init__.py')) as v_file:
     version = re.compile(r".*__version__ = '(.*?)'",
                          re.S).match(v_file.read()).group(1)
 
 requires = ['setuptools', 'pyyaml', 'click>=3.1', 'requests', 'IPy']
 
-tests_require = ['nose', 'coverage', 'tox']
+tests_require = []
 if sys.version_info < (2, 7):
     tests_require += ['unittest2', 'importlib']
 
@@ -55,7 +55,7 @@ setup(name='gandi.cli',
     zip_safe=False,
     install_requires=requires,
     tests_require=tests_require,
-    test_suite='nose.collector',
+    test_suite='gandi.cli.tests',
     extras_require=extras_require,
     entry_points={
         'console_scripts': [
