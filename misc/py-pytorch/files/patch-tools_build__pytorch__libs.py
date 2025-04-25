--- tools/build_pytorch_libs.py.orig	2025-04-24 16:28:33 UTC
+++ tools/build_pytorch_libs.py
@@ -119,7 +119,7 @@ def build_pytorch(
     cmake: CMake,
 ) -> None:
     my_env = _create_build_env()
-    checkout_nccl()
+    #checkout_nccl()
     build_test = not check_negative_env_flag("BUILD_TEST")
     cmake.generate(
         version, cmake_python_library, build_python, build_test, my_env, rerun_cmake
