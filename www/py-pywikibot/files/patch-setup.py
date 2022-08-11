--- setup.py.orig	2022-04-29 17:10:37 UTC
+++ setup.py
@@ -171,12 +171,12 @@ def get_validated_version():  # pragma: no cover
     from subprocess import PIPE, run
 
     from pkg_resources import parse_version, safe_version
-    try:
-        tags = run(['git', 'tag'], check=True, stdout=PIPE,
-                   universal_newlines=True).stdout.splitlines()
-    except Exception as e:
-        print(e)
-        sys.exit('Creating source distribution canceled.')
+    #try:
+    #    tags = run(['git', 'tag'], check=True, stdout=PIPE,
+    #               universal_newlines=True).stdout.splitlines()
+    #except Exception as e:
+    #    print(e)
+    #    sys.exit('Creating source distribution canceled.')
 
     for tag in ('stable', 'python2'):
         with suppress(ValueError):
