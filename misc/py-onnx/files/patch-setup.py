--- setup.py.orig	2022-02-07 19:42:28 UTC
+++ setup.py
@@ -61,11 +61,12 @@ COVERAGE = bool(os.getenv('COVERAGE', '0') == '1')
 # Version
 ################################################################################
 
-try:
-    git_version = subprocess.check_output(['git', 'rev-parse', 'HEAD'],
-                                          cwd=TOP_DIR).decode('ascii').strip()
-except (OSError, subprocess.CalledProcessError):
-    git_version = None
+#try:
+#    git_version = subprocess.check_output(['git', 'rev-parse', 'HEAD'],
+#                                          cwd=TOP_DIR).decode('ascii').strip()
+#except (OSError, subprocess.CalledProcessError):
+#    git_version = None
+git_version = None
 
 with open(os.path.join(TOP_DIR, 'VERSION_NUMBER')) as version_file:
     VERSION_NUMBER = version_file.read().strip()
