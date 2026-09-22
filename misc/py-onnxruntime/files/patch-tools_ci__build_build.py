--- tools/ci_build/build.py.orig	2026-09-10 06:09:41 UTC
+++ tools/ci_build/build.py
@@ -2100,6 +2100,8 @@ def build_python_wheel(
             cwd = os.path.join(cwd, config)
 
         args = [sys.executable, os.path.join(source_dir, "setup.py"), "bdist_wheel"]
+        if os.environ.get("ORT_DIST_DIR"):
+            args.extend(["--dist-dir", os.environ["ORT_DIST_DIR"]])
 
         # Any combination of the following arguments can be applied
         if nightly_build:
