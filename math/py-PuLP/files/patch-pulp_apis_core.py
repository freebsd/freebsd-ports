--- pulp/apis/core.py.orig	2020-06-16 01:55:06 UTC
+++ pulp/apis/core.py
@@ -149,6 +149,9 @@ elif sys.platform in ['darwin']:
     operating_system = "osx"
     arch = '64'
     PULPCFGFILE += ".osx"
+elif sys.platform in ['freebsd']:
+    operating_system = "freebsd"
+    PULPCFGFILE += ".freebsd"
 else:
     operating_system = "linux"
     PULPCFGFILE += ".linux"
@@ -375,4 +378,4 @@ try:
         return cList
 except(ImportError):
     def ctypesArrayFill(myList, type = None):
-        return None
\ No newline at end of file
+        return None
