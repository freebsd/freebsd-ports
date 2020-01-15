--- catfish/CatfishSearchEngine.py.orig	2020-01-15 01:49:54 UTC
+++ catfish/CatfishSearchEngine.py
@@ -24,6 +24,7 @@ import logging
 
 import io
 import os
+import platform
 import re
 import signal
 import subprocess
@@ -649,16 +650,17 @@ class CatfishSearchMethod_Locate(CatfishSearchMethodEx
             "existing": False,
             "regex": False
         }
-        try:
-            details = subprocess.check_output(["locate", "--help"])
-            details = details.decode("utf-8")
-            if "--existing" in details:
-                caps["existing"] = True
-            if "--regex" in details or "--regexp" in details:
-                caps["regex"] = True
+        if platform.system() != 'FreeBSD':
+            try:
+                details = subprocess.check_output(["locate", "--help"])
+                details = details.decode("utf-8")
+                if "--existing" in details:
+                    caps["existing"] = True
+                if "--regex" in details or "--regexp" in details:
+                    caps["regex"] = True
 
-        except subprocess.CalledProcessError:
-            pass
+            except subprocess.CalledProcessError:
+                pass
         return caps
 
     def assemble_query(self, keywords, path):
