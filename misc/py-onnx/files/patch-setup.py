--- setup.py.orig	2023-04-12 23:29:42 UTC
+++ setup.py
@@ -59,11 +59,12 @@ COVERAGE = bool(os.getenv("COVERAGE", "0") == "1")
 ################################################################################
 
 try:
-    git_version = (
-        subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=TOP_DIR)
-        .decode("ascii")
-        .strip()
-    )
+    #git_version = (
+    #    subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=TOP_DIR)
+    #    .decode("ascii")
+    #    .strip()
+    #)
+    git_version = None
 except (OSError, subprocess.CalledProcessError):
     git_version = None
 
