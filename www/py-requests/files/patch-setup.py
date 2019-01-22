# pytest-cov and its dependencies are not compulsory

--- setup.py.orig	2019-01-22 02:52:54 UTC
+++ setup.py
@@ -50,7 +50,6 @@ requires = [
 ]
 test_requirements = [
     'pytest-httpbin==0.0.7',
-    'pytest-cov',
     'pytest-mock',
     'pytest-xdist',
     'PySocks>=1.5.6, !=1.5.7',
