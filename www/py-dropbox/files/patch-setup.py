--- setup.py.orig	2022-07-13 18:09:08 UTC
+++ setup.py
@@ -31,9 +31,6 @@ install_reqs = [
 ]
 
 setup_requires = [
-    # Pin pytest-runner to 5.2.0, since 5.3.0 uses `find_namespaces` directive, not supported in
-    # Python 2.7
-    'pytest-runner == 5.2.0',
 ]
 
 # WARNING: This imposes limitations on test/requirements.txt such that the
