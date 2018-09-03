--- setup.py.orig	2018-08-30 12:28:10 UTC
+++ setup.py
@@ -28,19 +28,6 @@ tests_require = [
 ]
 
 
-server_require = [
-    'arrow>=0.12.1',
-    'click>=6.7',
-    'Flask-Admin==1.5.1',
-    'Flask-API>=0.6.9',
-    'Flask-Bootstrap>=3.3.7.1',
-    'flask-paginate>=0.5.1',
-    'Flask-WTF>=0.14.2',
-    'Flask>=0.12',
-    'requests>=2.18.4',
-    'Werkzeug>=0.11.15',
-]
-
 setup(
     name='buku',
     version=version,
@@ -63,11 +50,10 @@ setup(
     packages=find_packages(exclude=['tests']),
     include_package_data=True,
     entry_points={
-        'console_scripts': ['buku=buku:main', 'bukuserver=bukuserver.server:cli']
+        'console_scripts': ['buku=buku:main']
     },
     extras_require={
         'tests': tests_require,
-        'server': server_require,
         'packaging': ['twine>=1.11.0']
     },
     test_suite='tests',
