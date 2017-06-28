# pytest-cov and its dependencies are not compulsory

--- setup.py.orig	2017-06-04 15:11:40 UTC
+++ setup.py
@@ -45,7 +45,7 @@ requires = [
     'certifi>=2017.4.17'
 
 ]
-test_requirements = ['pytest-httpbin==0.0.7', 'pytest-cov', 'pytest-mock', 'pytest-xdist', 'PySocks>=1.5.6, !=1.5.7', 'pytest>=2.8.0']
+test_requirements = ['pytest-httpbin==0.0.7', 'pytest-mock', 'pytest-xdist', 'PySocks>=1.5.6, !=1.5.7', 'pytest>=2.8.0']
 
 about = {}
 with open(os.path.join(here, 'requests', '__version__.py'), 'r', 'utf-8') as f:
