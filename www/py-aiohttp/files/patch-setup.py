Obtained from:	https://github.com/aio-libs/aiohttp/commit/d7db1b90c59ae49660d5b469f6186d088a6d190d

--- setup.py.orig	2019-10-09 16:52:31 UTC
+++ setup.py
@@ -74,7 +74,7 @@ except IndexError:
 install_requires = [
     'attrs>=17.3.0',
     'chardet>=2.0,<4.0',
-    'multidict>=4.5,<5.0',
+    'multidict>=4.5,<6.0',
     'async_timeout>=3.0,<4.0',
     'yarl>=1.0,<2.0',
     'idna-ssl>=1.0; python_version<"3.7"',
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
 
 
