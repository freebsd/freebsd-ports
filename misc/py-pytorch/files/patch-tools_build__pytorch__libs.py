--- tools/build_pytorch_libs.py.orig	2026-03-23 18:40:49 UTC
+++ tools/build_pytorch_libs.py
@@ -93,7 +93,8 @@ def build_pytorch(
         and not check_negative_env_flag("USE_NCCL")
         and not check_env_flag("USE_SYSTEM_NCCL")
     ):
-        checkout_nccl()
+        #checkout_nccl()
+        pass
     build_test = not check_negative_env_flag("BUILD_TEST")
     cmake.generate(
         version, cmake_python_library, build_python, build_test, my_env, rerun_cmake
