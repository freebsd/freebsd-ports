--- setup.py.orig	2019-01-12 10:13:41 UTC
+++ setup.py
@@ -104,9 +104,12 @@ NEEDS_PYTEST = {'pytest', 'test'}.intersection(sys.arg
 pytest_runner = ['pytest-runner'] if NEEDS_PYTEST else []
 
 tests_require = [
-    'pytest', 'gunicorn',
+    'pytest>=3.8.2', 'gunicorn',
     'pytest-timeout', 'async-generator',
     'pytest-xdist',
+    'pytest-mock',
+    'trustme',
+    'brotlipy',
 ]
 
 
