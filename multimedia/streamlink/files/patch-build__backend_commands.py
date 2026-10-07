--- build_backend/commands.py.orig	2026-10-07 14:28:47 UTC
+++ build_backend/commands.py
@@ -17,7 +17,7 @@ class StreamlinkBuildPyCommand(build_py, Command):
 
 class StreamlinkBuildPyCommand(build_py, Command):
     def _build_plugins_json(self) -> None:
-        self.announce("building plugins JSON data", logging.INFO)
+        self.announce("building plugins JSON data")
         output = Path(self.build_lib) / STREAMLINK_PLUGINS_JSON
         output.parent.mkdir(parents=True, exist_ok=True)
         data = build()
