--- setup.py.orig	2012-08-06 14:46:03.000000000 +0800
+++ setup.py	2012-08-27 20:18:56.000000000 +0800
@@ -15,8 +15,6 @@
     os.system('python setup.py sdist upload')
     sys.exit()
 
-os.environ['PYTHONDONTWRITEBYTECODE'] = '1'
-
 packages = [
     'requests',
     'requests.packages',
@@ -27,11 +25,6 @@
 
 if is_py2:
     packages.extend([
-        'requests.packages.oauthlib',
-        'requests.packages.oauthlib.oauth1',
-        'requests.packages.oauthlib.oauth1.rfc5849',
-        'requests.packages.oauthlib.oauth2',
-        'requests.packages.oauthlib.oauth2.draft25',
         'requests.packages.chardet',
     ])
 else:
@@ -52,6 +45,7 @@
     package_data={'': ['LICENSE', 'NOTICE'], 'requests': ['*.pem']},
     package_dir={'requests': 'requests'},
     include_package_data=True,
+    exclude_package_data={'': ['oauthlib/*']},
     install_requires=requires,
     license=open('LICENSE').read(),
     classifiers=(
@@ -66,4 +60,6 @@
         'Programming Language :: Python :: 3.0',
         'Programming Language :: Python :: 3.1',
     ),
+    zip_safe=False,
+    test_suite='tests',
 )
