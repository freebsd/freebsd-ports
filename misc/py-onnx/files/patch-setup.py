--- setup.py.orig	2023-02-22 16:34:50 UTC
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
 
