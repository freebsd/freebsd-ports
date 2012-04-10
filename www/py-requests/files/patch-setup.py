--- setup.py.orig	2012-02-15 09:48:23.000000000 +0100
+++ setup.py	2012-04-01 12:00:30.000000000 +0200
@@ -4,10 +4,9 @@
 import os
 import sys
 import requests
-from requests.compat import is_py3, is_py2
 
 try:
-    from setuptools import setup
+    from setuptools import setup, find_packages
 except ImportError:
     from distutils.core import setup
 
@@ -21,21 +20,8 @@
     os.system('python test_requests.py')
     sys.exit()
 
-required = ['certifi>=0.0.7',]
-packages = [
-    'requests',
-    'requests.packages',
-    'requests.packages.urllib3',
-    'requests.packages.urllib3.packages',
-    'requests.packages.urllib3.packages.ssl_match_hostname',
-    'requests.packages.urllib3.packages.mimetools_choose_boundary',
-]
-
-if is_py3:
-    required.append('chardet2')
-else:
-    required.append('chardet>=1.0.0')
-    packages.append('requests.packages.oreos')
+# FreeBSD ports tree, provides only chardet2
+required = ['certifi>=0.0.7', 'chardet>=2.0.0']
 
 
 setup(
@@ -47,7 +33,7 @@
     author='Kenneth Reitz',
     author_email='me@kennethreitz.com',
     url='http://python-requests.org',
-    packages=packages,
+    packages=find_packages(exclude=['requests.packages.url*']),
     package_data={'': ['LICENSE', 'NOTICE']},
     include_package_data=True,
     install_requires=required,
