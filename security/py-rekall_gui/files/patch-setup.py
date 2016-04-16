--- setup.py.orig	2016-03-28 22:03:48 UTC
+++ setup.py
@@ -33,7 +33,8 @@ def find_data_files_directory(source):
     result = []
     for directory, _, files in os.walk(source):
         files = [os.path.join(directory, x) for x in files]
-        result.append((directory, files))
+        if files:
+            result.append((directory, files))
 
     return result
 
