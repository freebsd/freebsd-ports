--- setup.py.orig	2015-09-10 14:25:33 UTC
+++ setup.py
@@ -38,7 +38,8 @@ def find_data_files_directory(source):
     result = []
     for directory, _, files in os.walk(source):
         files = [os.path.join(directory, x) for x in files]
-        result.append((directory, files))
+        if files:
+            result.append((directory, files))
 
     return result
 
