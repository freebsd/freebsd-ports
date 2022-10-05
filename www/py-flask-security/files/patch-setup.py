- fix the problem that Python thinks that the version 2.6.2 is greater than 6.0.0 for pytest-runner

--- setup.py.orig	2022-10-05 06:23:53 UTC
+++ setup.py
@@ -42,7 +42,7 @@ for reqs in extras_require.values():
 
 setup_requires = [
     'Babel>=1.3',
-    'pytest-runner>=2.6.2',
+    'pytest-runner',
 ]
 
 install_requires = [
