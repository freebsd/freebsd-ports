- fix the problem that Python thinks that the version 2.7 is greater than 6.0.0 for pytest-runner

--- setup.py.orig	2022-10-04 20:58:57 UTC
+++ setup.py
@@ -54,7 +54,7 @@ for key, reqs in extras_require.items():
     extras_require['all'].extend(reqs)
 
 setup_requires = [
-    'pytest-runner>=2.7',
+    'pytest-runner',
     'setuptools_scm>=3.1.0',
 ]
 
