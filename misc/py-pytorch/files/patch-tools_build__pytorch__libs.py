--- tools/build_pytorch_libs.py.orig	2025-08-06 17:08:06 UTC
+++ tools/build_pytorch_libs.py
@@ -91,7 +91,8 @@ def build_pytorch(
         and not check_negative_env_flag("USE_NCCL")
         and not check_env_flag("USE_SYSTEM_NCCL")
     ):
-        checkout_nccl()
+        #checkout_nccl()
+        pass
     build_test = not check_negative_env_flag("BUILD_TEST")
     cmake.generate(
         version, cmake_python_library, build_python, build_test, my_env, rerun_cmake
