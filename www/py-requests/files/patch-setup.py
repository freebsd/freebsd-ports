--- setup.py.orig	2012-01-23 06:48:28.000000000 +0000
+++ setup.py	2012-02-07 16:11:32.000000000 +0000
@@ -4,10 +4,9 @@
 import os
 import sys
 import requests
-from requests.compat import is_py3
 
 try:
-    from setuptools import setup
+    from setuptools import setup, find_packages
 except ImportError:
     from distutils.core import setup
 
@@ -21,12 +20,8 @@
     os.system('python test_requests.py')
     sys.exit()
 
-required = ['certifi>=0.0.7',]
-
-if is_py3:
-    required.append('chardet2')
-else:
-    required.append('chardet>=1.0.0')
+# FreeBSD ports tree, provides only chardet2
+required = ['certifi>=0.0.7', 'chardet2>=1.0.0']
 
 
 setup(
@@ -38,15 +33,7 @@
     author='Kenneth Reitz',
     author_email='me@kennethreitz.com',
     url='http://python-requests.org',
-    packages=[
-        'requests',
-        'requests.packages',
-        'requests.packages.urllib3',
-        'requests.packages.urllib3.packages',
-        'requests.packages.urllib3.packages.ssl_match_hostname',
-        'requests.packages.urllib3.packages.mimetools_choose_boundary',
-        'requests.packages.oreos'
-    ],
+    packages=find_packages(where='.', exclude=['requests.packages.url*']),
     package_data={'': ['LICENSE', 'NOTICE']},
     include_package_data=True,
     install_requires=required,
