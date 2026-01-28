--- setup.py.orig	2021-11-06 01:31:13 UTC
+++ setup.py
@@ -276,7 +276,7 @@ setup(
     maintainer_email='rusty@rustcorp.com.au',
     license='MIT',
 
-    setup_requires=['cffi>=1.3.0', 'pytest-runner==2.6.2'],
+    setup_requires=['cffi>=1.3.0'],
     install_requires=['cffi>=1.3.0'],
     tests_require=['pytest==2.8.7'],
 
