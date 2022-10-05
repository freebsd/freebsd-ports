- fix the problem that Python thinks that the version 2.6.2 is greater than 6.0.0 for pytest-runner

--- setup.py.orig	2022-10-05 06:44:42 UTC
+++ setup.py
@@ -27,7 +27,7 @@ for reqs in extras_require.values():
     extras_require['all'].extend(reqs)
 
 setup_requires = [
-    'pytest-runner>=2.6.2',
+    'pytest-runner',
 ]
 
 install_requires = [
