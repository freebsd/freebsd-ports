--- ./setup.py.orig	2012-05-11 08:20:48.000000000 +1000
+++ ./setup.py	2012-06-02 19:09:45.000000000 +1000
@@ -29,7 +29,7 @@
 
 """
 
-from setuptools import setup
+from distutils.core import setup
 
 setup(
     name='grequests',
@@ -41,8 +41,6 @@
     description='Requests + Gevent',
     long_description=__doc__,
     py_modules=['grequests'],
-    zip_safe=False,
-    include_package_data=True,
     platforms='any',
     classifiers=[
         'Environment :: Web Environment',
