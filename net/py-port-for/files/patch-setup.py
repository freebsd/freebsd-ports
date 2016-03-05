--- setup.py.orig	2016-02-25 12:42:58 UTC
+++ setup.py
@@ -8,6 +8,11 @@ for cmd in ('egg_info', 'develop'):
 
 version='0.3.1'
 
+tests_require = [
+    'nose',
+    'mock>=0.8',
+]
+
 setup(
     name='port-for',
     version=version,
@@ -44,4 +49,7 @@ setup(
         'Topic :: System :: Systems Administration',
         'Topic :: Internet :: WWW/HTTP :: Site Management',
     ],
+
+    tests_require=tests_require,
+    test_suite='nose.collector',
 )
