--- tensorflow/tools/pip_package/build_pip_package.py.orig	2026-04-04 07:32:44 UTC
+++ tensorflow/tools/pip_package/build_pip_package.py
@@ -33,11 +33,12 @@ import tempfile
 import sys
 import tempfile
 
-from tensorflow.tools.pip_package.utils.utils import copy_file
-from tensorflow.tools.pip_package.utils.utils import create_init_files
-from tensorflow.tools.pip_package.utils.utils import is_macos
-from tensorflow.tools.pip_package.utils.utils import is_windows
-from tensorflow.tools.pip_package.utils.utils import replace_inplace
+sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
+from utils.utils import copy_file
+from utils.utils import create_init_files
+from utils.utils import is_macos
+from utils.utils import is_windows
+from utils.utils import replace_inplace
 
 
 def parse_args() -> argparse.Namespace:
@@ -397,6 +398,12 @@ def create_local_config_python(dst_dir: str) -> None:
   numpy_include_dir = "external/pypi_numpy/site-packages/numpy/_core/include"
   if not os.path.exists(numpy_include_dir):
     numpy_include_dir = "external/pypi_numpy/site-packages/numpy/core/include"
+  if not os.path.exists(numpy_include_dir):
+    _pylib = os.environ.get("PYTHON_LIB_PATH", "")
+    if _pylib:
+      numpy_include_dir = os.path.join(_pylib, "numpy", "_core", "include")
+      if not os.path.exists(numpy_include_dir):
+        numpy_include_dir = os.path.join(_pylib, "numpy", "core", "include")
   shutil.copytree(
       numpy_include_dir,
       os.path.join(dst_dir, "numpy_include"),
@@ -405,7 +412,12 @@ def create_local_config_python(dst_dir: str) -> None:
     path = "external/python_*/include"
   else:
     path = "external/python_*/include/python*"
-  shutil.copytree(glob.glob(path)[0], os.path.join(dst_dir, "python_include"))
+  _python_includes = glob.glob(path)
+  if not _python_includes:
+    import sysconfig
+    _inc = sysconfig.get_path('include')
+    if _inc and os.path.exists(_inc):
+      _python_includes = [_inc]
 
 
 def build_wheel(
