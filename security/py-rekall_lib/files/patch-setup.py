--- setup.py.orig	2019-01-04 00:51:27 UTC
+++ setup.py
@@ -41,11 +41,11 @@ def find_data_files(source):
     return result
 
 install_requires = [
-    "arrow==0.10.0",
+    "arrow>=0.10.0",
     "future",
     # We need to upgrade but this seems to break Rekall.
     #    "sortedcontainers >= 2.0, < 3.0",
-    "sortedcontainers==1.5.7",
+    "sortedcontainers>=1.5.7",
 ]
 
 data_files = (find_data_files("test_data") +
