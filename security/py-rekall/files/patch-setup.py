--- setup.py.orig	2016-11-03 22:17:38 UTC
+++ setup.py
@@ -80,7 +80,8 @@ def find_data_files(source):
     result = []
     for directory, _, files in os.walk(source):
         files = [os.path.join(directory, x) for x in files]
-        result.append((directory, files))
+        if files:
+            result.append((directory, files))
 
     return result
 
