--- hatch_build.py.orig	2020-02-02 00:00:00 UTC
+++ hatch_build.py
@@ -14,6 +14,8 @@ import sys
 import platform
 import sys
 
+import packaging.tags
+
 from pathlib import Path
 from typing import Any
 
@@ -70,15 +72,10 @@ def get_wheel_platform_tag() -> str:
 def get_wheel_platform_tag() -> str:
     """Get the platform tag for the output wheel.
 
-    This is the tag that will be used in the wheel filename.
-    We use manylinux_2_28 for Linux for broad compatibility.
-
-    Uses cibuildwheel environment variables when available to get
-    the correct target architecture for cross-compilation.
+    Use packaging.tags so that every platform gets the correct
+    platform-specific tag automatically.
     """
-    system = platform.system().lower()
-    machine = _get_target_architecture(system)
-    return _get_platform_tag_for_system(system, machine)
+    return next(packaging.tags.sys_tags()).platform
 
 
 def get_python_tag() -> str:
@@ -93,21 +90,10 @@ class CustomBuildHook(BuildHookInterface[Any]):
 
     def initialize(self, version: str, build_data: dict[str, Any]) -> None:
         """Download and bundle pytauri-wheel for the target platform."""
-        # Ensure frontend assets exist for every target (wheel, sdist, editable wheel).
-        # build_assets.py lives next to hatch_build.py at <self.root>/build_assets.py.
-        sys.path.insert(0, self.root)
-        try:
-            from build_assets import download_all_assets, verify_assets
-        finally:
-            sys.path.pop(0)
-
-        self.app.display_info("Ensuring frontend assets are present")
-        download_all_assets()
-        missing = [name for name, ok in verify_assets().items() if not ok]
-        if missing:
-            self.app.display_warning(
-                f"Frontend assets unavailable from CDN - placeholders used: {missing}"
-            )
+        # Frontend assets are already shipped in the PyPI sdist; skip the
+        # CDN download step so the build works offline in the ports framework.
+        self.app.display_info("Skipping frontend asset download during port build")
+        missing = []
 
         # Skip pytauri-wheel bundling for non-wheel builds (sdist) and editable installs.
         if self.target_name != "wheel":
