--- setup.py.orig	2020-11-12 18:52:12 UTC
+++ setup.py
@@ -47,7 +47,7 @@ def package_files(directory):
 
 
 install_requires = [
-    'yara-python==3.11.0',
+    'yara-python>=3.11.0',
 ]
 
 dev_requires = [
