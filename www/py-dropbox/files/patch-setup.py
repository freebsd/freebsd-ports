--- setup.py.orig	2022-11-09 23:21:58 UTC
+++ setup.py
@@ -27,13 +27,10 @@ install_reqs = [
 install_reqs = [
     'requests >= 2.16.2',
     'six >= 1.12.0',
-    'stone >= 2.*',
+    'stone >= 2.0',
 ]
 
 setup_requires = [
-    # Pin pytest-runner to 5.2.0, since 5.3.0 uses `find_namespaces` directive, not supported in
-    # Python 2.7
-    'pytest-runner == 5.2.0',
 ]
 
 # WARNING: This imposes limitations on test/requirements.txt such that the
