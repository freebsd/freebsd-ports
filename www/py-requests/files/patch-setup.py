# 1: Backport bumping idna max version
# https://github.com/requests/requests/commit/991e8b76b7a9d21f698b24fa0058d3d5968721bc
# 2: pytest-cov and its dependencies are not compulsory

--- setup.py.orig	2017-08-15 13:19:39 UTC
+++ setup.py
@@ -43,12 +43,12 @@ packages = ['requests']
 
 requires = [
     'chardet>=3.0.2,<3.1.0',
-    'idna>=2.5,<2.7',
+    'idna>=2.5,<2.8',
     'urllib3>=1.21.1,<1.23',
     'certifi>=2017.4.17'
 
 ]
-test_requirements = ['pytest-httpbin==0.0.7', 'pytest-cov', 'pytest-mock', 'pytest-xdist', 'PySocks>=1.5.6, !=1.5.7', 'pytest>=2.8.0']
+test_requirements = ['pytest-httpbin==0.0.7', 'pytest-mock', 'pytest-xdist', 'PySocks>=1.5.6, !=1.5.7', 'pytest>=2.8.0']
 
 about = {}
 with open(os.path.join(here, 'requests', '__version__.py'), 'r', 'utf-8') as f:
