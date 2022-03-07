https://github.com/formencode/formencode/commit/74bbd2ea74aa

--- setup.py.orig	2015-02-07 10:32:40 UTC
+++ setup.py
@@ -11,11 +11,11 @@ from setuptools import setup, find_packages
 
 version = '1.3.0'
 
-if not '2.6' <= sys.version < '3.0' and not '3.2' <= sys.version:
+if not (2,6) <= sys.version_info[:2] < (3,0) and not (3,2) <= sys.version_info[:2]:
     raise ImportError('Python version not supported')
 
 tests_require = ['nose', 'pycountry',
-    'dnspython' if sys.version < '3.0' else 'dnspython3']
+    'dnspython' if sys.version_info < (3,0) else 'dnspython3']
 
 doctests = ['docs/htmlfill.txt', 'docs/Validator.txt',
     'formencode/tests/non_empty.txt']
