--- setup.py.orig	2023-07-06 07:11:10 UTC
+++ setup.py
@@ -141,12 +141,12 @@ def get_validated_version() -> str:
     from subprocess import PIPE, run
 
     from pkg_resources import parse_version, safe_version
-    try:
-        tags = run(['git', 'tag'], check=True, stdout=PIPE,
-                   universal_newlines=True).stdout.splitlines()
-    except Exception as e:  # pragma: no cover
-        print(e)
-        sys.exit('Creating source distribution canceled.')
+    #try:
+    #    tags = run(['git', 'tag'], check=True, stdout=PIPE,
+    #               universal_newlines=True).stdout.splitlines()
+    #except Exception as e:  # pragma: no cover
+    #    print(e)
+    #    sys.exit('Creating source distribution canceled.')
 
     last_tag = None
     if tags:  # pragma: no cover
