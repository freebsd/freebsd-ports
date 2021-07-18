--- setup.py.orig	2021-06-01 06:43:44 UTC
+++ setup.py
@@ -158,12 +158,12 @@ def get_validated_version():  # pragma: no cover
     # validate version for sdist
     from contextlib import suppress
     from subprocess import PIPE, run
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
