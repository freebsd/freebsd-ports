--- setup.py.orig	2017-11-05 21:38:24 UTC
+++ setup.py
@@ -41,9 +41,9 @@ def find_data_files(source):
     return result
 
 install_requires = [
-    "arrow==0.10.0",
+    "arrow>=0.10.0",
     "future",
-    "sortedcontainers==1.5.7",
+    "sortedcontainers>=1.5.7",
 ]
 
 data_files = (find_data_files("test_data") +
