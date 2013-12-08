--- ./setup.py.orig	2013-12-07 23:20:33.881977668 +1100
+++ ./setup.py	2013-12-07 23:20:46.477070760 +1100
@@ -24,7 +24,7 @@
 
     packages=find_packages(),
     package_data={'dpaste': ['static/*.*', 'templates/*.*']},
-    scripts=('manage.py',),
+    include_package_data=True,
     install_requires=(
         'django>=1.4',
         'django-mptt>=0.6.0',
