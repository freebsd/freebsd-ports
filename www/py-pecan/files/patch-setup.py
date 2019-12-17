--- setup.py.orig	2019-12-16 02:09:56 UTC
+++ setup.py
@@ -1,3 +1,7 @@
+# virtualenv is not a compulsory test dependency
+# make it an extras_require[dev] instead
+# TODO: Upstream
+
 import sys
 import platform
 
@@ -29,7 +33,6 @@ except:
 
 
 tests_require = requirements + [
-    'virtualenv',
     'Jinja2',
     'gunicorn',
     'mock',
