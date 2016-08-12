--- setup.py.orig	2016-08-08 13:44:46 UTC
+++ setup.py
@@ -111,6 +111,7 @@ setup(
   install_requires = ['iso8601', 'six'],
   packages = find_packages(exclude=['tests']),
   extras_require = extras,
+  test_suite='tests',
   scripts = [
     'tuf/client/basic_client.py'
   ]
