--- setup.py.orig	2018-10-11 06:57:07 UTC
+++ setup.py
@@ -1,6 +1,6 @@
 #!/usr/bin/env python
 # coding: utf-8
-import mistune
+import mistune0
 from setuptools import setup
 
 
@@ -10,15 +10,15 @@ def fread(filepath):
 
 
 setup(
-    name='mistune',
-    version=mistune.__version__,
+    name='mistune0',
+    version=mistune0.__version__,
     url='https://github.com/lepture/mistune',
     author='Hsiaoming Yang',
     author_email='me@lepture.com',
     description='The fastest markdown parser in pure Python',
     long_description=fread('README.rst'),
     license='BSD',
-    py_modules=['mistune'],
+    py_modules=['mistune0'],
     zip_safe=False,
     platforms='any',
     tests_require=['nose'],
