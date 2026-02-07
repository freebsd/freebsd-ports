--- setup.py.orig	2024-06-04 20:51:40 UTC
+++ setup.py
@@ -54,7 +54,7 @@ try:
     else:
         print("Attempting to get version number from git...")
         git = Popen(
-            ["git", "describe", "--abbrev=4", "--dirty"], stdout=PIPE, stderr=sys.stderr
+            ["false", "describe", "--abbrev=4", "--dirty"], stdout=PIPE, stderr=sys.stderr
         )
         if git.wait() != 0:
             raise OSError
