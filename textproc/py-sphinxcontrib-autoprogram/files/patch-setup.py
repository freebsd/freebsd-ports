--- setup.py.orig	2024-04-07 02:53:48 UTC
+++ setup.py
@@ -3,7 +3,7 @@ from __future__ import with_statement
 
 import sys
 
-from setuptools import setup, find_packages
+from setuptools import find_namespace_packages, setup, find_packages
 
 
 # Do not change the variable name.  It's parsed by doc/conf.py script.
@@ -49,8 +49,7 @@ setup(
     ],
     python_requires='>=3.8',
     platforms='any',
-    packages=find_packages(),
-    namespace_packages=['sphinxcontrib'],
+    packages=find_namespace_packages(include=['sphinxcontrib']),
     include_package_data=True,
     install_requires=requires,
     test_suite='sphinxcontrib.autoprogram.suite'
