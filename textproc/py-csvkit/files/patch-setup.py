--- setup.py.orig	2015-03-31 01:07:39 UTC
+++ setup.py
@@ -6,9 +6,9 @@ from setuptools import setup
 install_requires = [
     'xlrd>=0.7.1',
     'sqlalchemy>=0.6.6',
-    'openpyxl==2.2.0-b1',
+    'openpyxl>=2.2.0-b1',
     'six>=1.6.1',
-    'python-dateutil==2.2'
+    'python-dateutil>=2.2'
 ]
 
 if sys.version_info < (2, 7):
@@ -17,7 +17,7 @@ if sys.version_info < (2, 7):
     install_requires.append('simplejson>=3.6.3')
 
 if sys.version_info[0] == 2:
-    install_requires.append('dbf==0.94.003')
+    install_requires.append('dbf>=0.94.003')
 
 setup(
     name='csvkit',
