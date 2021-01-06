--- setup.py.orig	2021-01-02 04:58:38.335383000 -0500
+++ setup.py	2021-01-02 04:58:58.712756000 -0500
@@ -2,13 +2,13 @@
 from setuptools import setup
 
 packages = \
-['ospd_openvas', 'tests']
+['ospd_openvas']
 
 package_data = \
 {'': ['*']}
 
 modules = \
-['ospd-openvas', 'ospd', 'CHANGELOG', 'COPYING', 'poetry', 'setup', 'MANIFEST']
+['ospd-openvas', 'ospd']
 install_requires = \
 ['ospd>=20.8,<21.0',
  'packaging>=20.4,<21.0',
