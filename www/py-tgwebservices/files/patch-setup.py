--- setup.py.orig	2010-01-29 22:33:35.000000000 +0800
+++ setup.py	2011-03-04 17:03:45.000000000 +0800
@@ -1,5 +1,4 @@
-from setuptools import setup, find_packages
-from finddata import find_package_data
+from setuptools import setup
 
 import os
 execfile(os.path.join("tgwebservices", "release.py"))
@@ -22,9 +21,8 @@
     ],
     scripts = [],
     zip_safe=False,
-    packages=find_packages(),
-    package_data = find_package_data(where='tgwebservices',
-                                     package='tgwebservices'),
+    packages=['tgwebservices', 'tgwebservices.templates'],
+    package_data = {'tgwebservices': ['templates/*.html']},
     keywords = [
         "turbogears.extension"
     ],
