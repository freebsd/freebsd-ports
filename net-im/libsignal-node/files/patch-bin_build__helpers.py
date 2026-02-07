broken with https://github.com/signalapp/libsignal/commit/64c186d4de31b6180f629333129f86ee84ad8349

--- bin/build_helpers.py.orig	2025-06-02 15:44:46 UTC
+++ bin/build_helpers.py
@@ -13,6 +13,7 @@ def rust_paths_to_remap() -> Iterator[str]:
 
 
 def rust_paths_to_remap() -> Iterator[str]:
+    return ""
     # Repo root
     yield os.path.dirname(os.path.abspath(os.path.dirname(__file__)))
 
