--- setup.py.orig	2026-09-10 06:09:41 UTC
+++ setup.py
@@ -443,6 +443,12 @@ elif platform.system() == "Darwin":
     libs.extend(["libonnxruntime_providers_vitisai.dylib"])
     if nightly_build:
         libs.extend(["libonnxruntime_pywrapper.dylib"])
+elif platform.system() == "FreeBSD":
+    libs = [
+        "onnxruntime_pybind11_state.so",
+        "libonnxruntime_providers_shared.so",
+        "libonnxruntime.so*",
+    ]
 else:
     libs = [
         "onnxruntime_pybind11_state.pyd",
