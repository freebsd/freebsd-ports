--- setup.py.orig	2023-07-04 19:21:51 UTC
+++ setup.py
@@ -42,7 +42,7 @@ setup(
 pytest_runner = ['pytest-runner'] if needs_pytest else []
 
 setup(
-    name=about['__title__'],
+    name='mechanicalsoup',
 
     # useful: python setup.py sdist bdist_wheel upload
     version=about['__version__'],
