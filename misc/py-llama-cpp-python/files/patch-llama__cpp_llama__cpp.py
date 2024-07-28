--- llama_cpp/llama_cpp.py.orig	2024-07-28 03:36:26 UTC
+++ llama_cpp/llama_cpp.py
@@ -28,7 +28,7 @@ def _load_shared_library(lib_base_name: str):
     # for llamacpp) and "llama" (default name for this repo)
     _lib_paths: List[pathlib.Path] = []
     # Determine the file extension based on the platform
-    if sys.platform.startswith("linux"):
+    if sys.platform.startswith("linux") or sys.platform.startswith("freebsd"):
         _lib_paths += [
             _base_path / f"lib{lib_base_name}.so",
         ]
