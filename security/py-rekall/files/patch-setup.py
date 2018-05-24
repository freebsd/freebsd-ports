--- setup.py.orig	2017-11-05 21:24:44 UTC
+++ setup.py
@@ -82,7 +82,8 @@ def find_data_files(source):
     result = []
     for directory, _, files in os.walk(source):
         files = [os.path.join(directory, x) for x in files]
-        result.append((directory, files))
+        if files:
+            result.append((directory, files))
 
     return result
 
@@ -95,7 +96,6 @@ commands = dict(
 # This requires an exact version to ensure that installing the meta package
 # pulls in tested dependencies.
 install_requires = [
-    "rekall-agent >= 1.7.0rc1, < 1.8",
     "rekall-lib >= 1.7.0rc1, < 1.8",
     "rekall-core >= 1.7.0rc1, < 1.8",
     "ipython >= 5.0.0, < 7.0",
