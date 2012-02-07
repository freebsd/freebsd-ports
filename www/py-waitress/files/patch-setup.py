--- setup.py.orig	2012-01-31 07:25:31.000000000 +0100
+++ setup.py	2012-01-31 16:09:30.000000000 +0100
@@ -50,7 +50,7 @@
         'Topic :: Internet :: WWW/HTTP',
         ],
     url='https://github.com/Pylons/waitress',
-    packages=find_packages(),
+    packages=find_packages(where='.', exclude=['waitress.test*']),
     install_requires=[
         'setuptools',
         ],
