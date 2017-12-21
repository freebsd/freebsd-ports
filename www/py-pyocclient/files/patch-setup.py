Fix reading of utf-8 formatted files in setup script and fix build
with Python 3.x.

https://github.com/owncloud/pyocclient/commit/aa6b4374a779bf0f9e060117b2e8d1e810342bc8

--- setup.py.orig	2017-01-26 05:22:41 UTC
+++ setup.py
@@ -3,18 +3,19 @@
 # vim: expandtab shiftwidth=4 softtabstop=4
 #
 from setuptools import setup
+import io
 
 version = '0.4'
 
 long_description = (
-    open('README.rst').read()
+    io.open('README.rst', encoding='utf-8').read()
     + '\n' +
     'Contributors\n'
     '============\n'
     + '\n' +
-    open('docs/source/CONTRIBUTORS.rst').read()
+    io.open('docs/source/CONTRIBUTORS.rst', encoding='utf-8').read()
     + '\n' +
-    open('CHANGES.rst').read()
+    io.open('CHANGES.rst', encoding='utf-8').read()
     + '\n')
 
 setup(
