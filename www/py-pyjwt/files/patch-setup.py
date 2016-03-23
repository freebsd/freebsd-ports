--- setup.py.orig	2016-02-26 09:43:54 UTC
+++ setup.py
@@ -31,8 +31,6 @@ if sys.argv[-1] == 'publish':
 
 tests_require = [
     'pytest',
-    'pytest-cov',
-    'pytest-runner',
 ]
 
 setup(
@@ -61,7 +59,6 @@ setup(
         'Topic :: Utilities',
     ],
     test_suite='tests',
-    setup_requires=['pytest-runner'],
     tests_require=tests_require,
     extras_require=dict(
         test=tests_require,
