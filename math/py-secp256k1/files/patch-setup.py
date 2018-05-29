--- setup.py.orig	2016-09-16 14:22:47 UTC
+++ setup.py
@@ -263,7 +263,7 @@ setup(
     author_email='lud@tutanota.com',
     license='MIT',
 
-    setup_requires=['cffi>=1.3.0', 'pytest-runner==2.6.2'],
+    setup_requires=['cffi>=1.3.0'],
     install_requires=['cffi>=1.3.0'],
     tests_require=['pytest==2.8.7'],
 
