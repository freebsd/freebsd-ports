--- src/common/gen/main.py.orig	2026-05-10 11:25:04 UTC
+++ src/common/gen/main.py
@@ -10,7 +10,7 @@ from typing import Any, Dict
 from traceback import format_exc
 from typing import Any, Dict
 
-for deps_path in [join(sep, "usr", "share", "bunkerweb", *paths) for paths in (("deps", "python"), ("utils",), ("api",))]:
+for deps_path in [join(sep, "usr", "local", "share", "bunkerweb", "common", *paths) for paths in (("deps", "python"), ("utils",), ("api",))]:
     if deps_path not in sys_path:
         sys_path.append(deps_path)
 
@@ -18,7 +18,7 @@ from Templator import Templator
 from Configurator import Configurator
 from Templator import Templator
 
-DB_PATH = Path(sep, "usr", "share", "bunkerweb", "db")
+DB_PATH = Path(sep, "usr", "local", "share", "bunkerweb", "common", "db")
 
 LOGGER = getLogger("GENERATOR")
 
@@ -26,15 +26,15 @@ if __name__ == "__main__":
     try:
         # Parse arguments
         parser = ArgumentParser(description="BunkerWeb config generator")
-        parser.add_argument("--settings", default=join(sep, "usr", "share", "bunkerweb", "settings.json"), type=str, help="file containing the main settings")
+        parser.add_argument("--settings", default=join(sep, "usr", "local", "share", "bunkerweb", "common", "settings.json"), type=str, help="file containing the main settings")
         parser.add_argument(
-            "--templates", default=join(sep, "usr", "share", "bunkerweb", "confs"), type=str, help="directory containing the main template files"
+            "--templates", default=join(sep, "usr", "local", "share", "bunkerweb", "common", "confs"), type=str, help="directory containing the main template files"
         )
-        parser.add_argument("--core", default=join(sep, "usr", "share", "bunkerweb", "core"), type=str, help="directory containing the core plugins")
-        parser.add_argument("--plugins", default=join(sep, "etc", "bunkerweb", "plugins"), type=str, help="directory containing the external plugins")
-        parser.add_argument("--pro-plugins", default=join(sep, "etc", "bunkerweb", "pro", "plugins"), type=str, help="directory containing the pro plugins")
-        parser.add_argument("--output", default=join(sep, "etc", "nginx"), type=str, help="where to write the rendered files")
-        parser.add_argument("--target", default=join(sep, "etc", "nginx"), type=str, help="where nginx will search for configurations files")
+        parser.add_argument("--core", default=join(sep, "usr", "local", "share", "bunkerweb", "common", "core"), type=str, help="directory containing the core plugins")
+        parser.add_argument("--plugins", default=join(sep, "usr", "local", "etc", "bunkerweb", "plugins"), type=str, help="directory containing the external plugins")
+        parser.add_argument("--pro-plugins", default=join(sep, "usr", "local", "etc", "bunkerweb", "pro", "plugins"), type=str, help="directory containing the pro plugins")
+        parser.add_argument("--output", default=join(sep, "usr", "local", "etc", "nginx"), type=str, help="where to write the rendered files")
+        parser.add_argument("--target", default=join(sep, "usr", "local", "etc", "nginx"), type=str, help="where nginx will search for configurations files")
         parser.add_argument("--variables", type=str, help="path to the file containing environment variables")
         args = parser.parse_args()
 
