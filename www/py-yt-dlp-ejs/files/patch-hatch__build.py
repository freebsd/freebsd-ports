--- hatch_build.py.orig	2020-02-02 00:00:00 UTC
+++ hatch_build.py
@@ -11,6 +11,17 @@ class CustomBuildHook(BuildHookInterface):
 
 class CustomBuildHook(BuildHookInterface):
     def initialize(self, version, build_data):
+        # Skip bundling if dist files already exist (FreeBSD pre-builds them)
+        if os.path.exists("dist/yt.solver.core.min.js") and os.path.exists("dist/yt.solver.lib.min.js"):
+            print("Using pre-built JavaScript bundles...")
+            build_data["force_include"].update(
+                {
+                    "dist/yt.solver.core.min.js": "yt_dlp_ejs/yt/solver/core.min.js",
+                    "dist/yt.solver.lib.min.js": "yt_dlp_ejs/yt/solver/lib.min.js",
+                }
+            )
+            return
+
         name, cmds, env = build_bundle_cmds()
         if cmds is None:
             raise RuntimeError(
