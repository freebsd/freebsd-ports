--- setup.py.orig	2024-09-30 20:12:15 UTC
+++ setup.py
@@ -66,11 +66,12 @@ try:
 ################################################################################
 
 try:
-    _git_version = (
-        subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=TOP_DIR)
-        .decode("ascii")
-        .strip()
-    )
+    #_git_version = (
+    #    subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=TOP_DIR)
+    #    .decode("ascii")
+    #    .strip()
+    #)
+    _git_version = ""
 except (OSError, subprocess.CalledProcessError):
     _git_version = ""
 
@@ -228,10 +229,7 @@ class BuildPy(setuptools.command.build_py.build_py):
 
 class BuildPy(setuptools.command.build_py.build_py):
     def run(self):
-        if self.editable_mode:
-            dst_dir = TOP_DIR
-        else:
-            dst_dir = self.build_lib
+        dst_dir = self.build_lib
         create_version(dst_dir)
         return super().run()
 
@@ -274,10 +272,7 @@ class BuildExt(setuptools.command.build_ext.build_ext)
             self.copy_file(src, dst)
 
         # Copy over the generated python files to build/source dir depending on editable mode
-        if self.editable_mode:
-            dst_dir = TOP_DIR
-        else:
-            dst_dir = build_lib
+        dst_dir = build_lib
 
         generated_py_files = glob.glob(os.path.join(CMAKE_BUILD_DIR, "onnx", "*.py"))
         generated_pyi_files = glob.glob(os.path.join(CMAKE_BUILD_DIR, "onnx", "*.pyi"))
