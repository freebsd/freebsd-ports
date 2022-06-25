--- setup.py.orig	2022-06-15 20:13:03 UTC
+++ setup.py
@@ -56,11 +56,12 @@ COVERAGE = bool(os.getenv("COVERAGE", "0") == "1")
 # Version
 ################################################################################
 
-try:
-    git_version = subprocess.check_output(["git", "rev-parse", "HEAD"],
-                                          cwd=TOP_DIR).decode("ascii").strip()
-except (OSError, subprocess.CalledProcessError):
-    git_version = None
+#try:
+#    git_version = subprocess.check_output(["git", "rev-parse", "HEAD"],
+#                                          cwd=TOP_DIR).decode("ascii").strip()
+#except (OSError, subprocess.CalledProcessError):
+#    git_version = None
+git_version = None
 
 with open(os.path.join(TOP_DIR, "VERSION_NUMBER")) as version_file:
     VERSION_NUMBER = version_file.read().strip()
