--- setup.py.orig	2014-08-14 18:05:14 UTC
+++ setup.py
@@ -1,13 +1,18 @@
 #!/usr/bin/env python
 
 from setuptools import setup
+import sys
+
+open_kwargs = {}
+if sys.version_info.major >= 3:
+    open_kwargs['encoding'] = 'utf8'
 
 setup(name='tabletext',
       version='0.1',
       description='Python library and command line utility to pretty-print\
       tabular data',
-      long_description=open("README.rst").read() + "\n"
-      + open("CHANGELOG.rst").read(),
+      long_description=open("README.rst", **open_kwargs).read() + "\n"
+      + open("CHANGELOG.rst", **open_kwargs).read(),
       url='https://github.com/Thibauth/tabletext',
       author='Thibaut Horel',
       author_email='thibaut.horel+tabletext@gmail.com',
