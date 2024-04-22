--- setup.py.orig	2024-03-25 14:15:57 UTC
+++ setup.py
@@ -65,11 +65,12 @@ try:
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
 
@@ -227,10 +228,7 @@ class BuildPy(setuptools.command.build_py.build_py):
 
 class BuildPy(setuptools.command.build_py.build_py):
     def run(self):
-        if self.editable_mode:
-            dst_dir = TOP_DIR
-        else:
-            dst_dir = self.build_lib
+        dst_dir = self.build_lib
         create_version(dst_dir)
         return super().run()
 
@@ -273,10 +271,7 @@ class BuildExt(setuptools.command.build_ext.build_ext)
             self.copy_file(src, dst)
 
         # Copy over the generated python files to build/source dir depending on editable mode
-        if self.editable_mode:
-            dst_dir = TOP_DIR
-        else:
-            dst_dir = build_lib
+        dst_dir = build_lib
 
         generated_py_files = glob.glob(os.path.join(CMAKE_BUILD_DIR, "onnx", "*.py"))
         generated_pyi_files = glob.glob(os.path.join(CMAKE_BUILD_DIR, "onnx", "*.pyi"))
