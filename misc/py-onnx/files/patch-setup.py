--- setup.py.orig	2022-11-09 10:56:10 UTC
+++ setup.py
@@ -56,11 +56,12 @@ COVERAGE = bool(os.getenv("COVERAGE", "0") == "1")
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
 
