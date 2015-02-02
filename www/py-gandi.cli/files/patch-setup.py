--- setup.py.orig	2015-01-08 09:26:15 UTC
+++ setup.py
@@ -6,10 +6,11 @@ import os
 import sys
 
 from setuptools import setup, find_packages
+from io import open
 
 here = os.path.abspath(os.path.dirname(__file__))
-README = open(os.path.join(here, 'README.md')).read()
-CHANGES = open(os.path.join(here, 'CHANGES.rst')).read()
+README = open(os.path.join(here, 'README.md'), encoding='utf-8').read()
+CHANGES = open(os.path.join(here, 'CHANGES.rst'), encoding='utf-8').read()
 
 
 with open(os.path.join(here, 'gandi', 'cli', '__init__.py')) as v_file:
@@ -49,6 +50,7 @@ setup(name='gandi.cli',
       zip_safe=False,
       install_requires=requires,
       tests_require=tests_require,
+      test_suite='gandi.cli.tests',
       extras_require=extras_require,
       entry_points="""\
 [console_scripts]
