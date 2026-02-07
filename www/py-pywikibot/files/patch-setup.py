--- setup.py.orig	2024-03-09 06:20:55 UTC
+++ setup.py
@@ -160,12 +160,12 @@ def get_validated_version(name: str) -> str:  # pragma
 
     from packaging.version import InvalidVersion, Version
 
-    try:
-        tags = run(['git', 'tag'], check=True, stdout=PIPE,
-                   text=True).stdout.splitlines()
-    except Exception as e:
-        print(e)
-        sys.exit('Creating source distribution canceled.')
+    #try:
+    #    tags = run(['git', 'tag'], check=True, stdout=PIPE,
+    #               text=True).stdout.splitlines()
+    #except Exception as e:
+    #    print(e)
+    #    sys.exit('Creating source distribution canceled.')
 
     last_tag = None
     if tags:
