--- setup.py.orig	2026-08-15 00:00:00 UTC
+++ setup.py
@@ -434,6 +434,12 @@ elif platform.system() == "Darwin":
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
