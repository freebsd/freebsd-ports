--- configure.py.orig	2021-01-04 20:18:42 UTC
+++ configure.py
@@ -475,7 +475,7 @@ def check_bazel_version(min_version, max_version):
     print('Cannot find bazel. Please install bazel.')
     sys.exit(0)
   curr_version = run_shell(
-      ['bazel', '--batch', '--bazelrc=/dev/null', 'version'])
+      ['bazel', '--batch', '--output_user_root=/tmp/.bazel', '--bazelrc=/dev/null', 'version'])
 
   for line in curr_version.split('\n'):
     if 'Build label: ' in line:
