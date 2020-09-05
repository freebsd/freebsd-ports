--- setup.py.orig	2020-09-05 06:11:40 UTC
+++ setup.py
@@ -173,12 +173,12 @@ def get_validated_version():  # pragma: no cover
     # validate version for sdist
     from contextlib import suppress
     from subprocess import run, PIPE
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
