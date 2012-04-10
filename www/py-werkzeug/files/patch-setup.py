--- setup.py.orig	2011-12-16 14:52:45.000000000 +0000
+++ setup.py	2012-02-02 09:36:45.000000000 +0000
@@ -54,7 +54,7 @@
 .. _github: http://github.com/mitsuhiko/werkzeug
 """
 try:
-    from setuptools import setup
+    from setuptools import setup, find_packages
 except ImportError:
     from distutils.core import setup
 
@@ -78,10 +78,8 @@
         'Topic :: Internet :: WWW/HTTP :: Dynamic Content',
         'Topic :: Software Development :: Libraries :: Python Modules'
     ],
-    packages=['werkzeug', 'werkzeug.debug', 'werkzeug.contrib',
-              'werkzeug.testsuite', 'werkzeug.testsuite.contrib'],
+    packages=find_packages(where='.', exclude=['werkzeug.test*']),
     include_package_data=True,
-    test_suite='werkzeug.testsuite.suite',
     zip_safe=False,
     platforms='any'
 )
