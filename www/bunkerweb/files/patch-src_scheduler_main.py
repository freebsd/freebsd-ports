--- src/scheduler/main.py.orig	2026-11-20 19:02:21 UTC
+++ src/scheduler/main.py
@@ -24,7 +24,7 @@ from typing import Any, Dict, List, Literal, Optional,
 from traceback import format_exc
 from typing import Any, Dict, List, Literal, Optional, Set, Tuple, Union, cast
 
-BUNKERWEB_PATH = Path(sep, "usr", "share", "bunkerweb")
+BUNKERWEB_PATH = Path(sep, "usr", "local", "share", "bunkerweb")
 
 for deps_path in [BUNKERWEB_PATH.joinpath(*paths).as_posix() for paths in (("deps", "python"), ("utils",), ("api",), ("db",), ("gen",))]:
     if deps_path not in sys_path:
@@ -77,7 +77,7 @@ CACHE_PATH = Path(sep, "var", "cache", "bunkerweb")
 
 CACHE_PATH = Path(sep, "var", "cache", "bunkerweb")
 
-CUSTOM_CONFIGS_PATH = Path(sep, "etc", "bunkerweb", "configs")
+CUSTOM_CONFIGS_PATH = Path(sep, "usr", "local", "etc", "bunkerweb", "configs")
 CUSTOM_CONFIGS_DIRS = (
     "http",
     "stream",
@@ -90,12 +90,12 @@ CUSTOM_CONFIGS_DIRS = (
     "crs-plugins-after",
 )
 
-CONFIG_PATH = Path(sep, "etc", "nginx")
+CONFIG_PATH = Path(sep, "usr", "local", "etc", "nginx")
 NGINX_VARIABLES_PATH = CONFIG_PATH.joinpath("variables.env")
 
-EXTERNAL_PLUGINS_PATH = Path(sep, "etc", "bunkerweb", "plugins")
+EXTERNAL_PLUGINS_PATH = Path(sep, "usr", "local", "etc", "bunkerweb", "plugins")
 
-PRO_PLUGINS_PATH = Path(sep, "etc", "bunkerweb", "pro", "plugins")
+PRO_PLUGINS_PATH = Path(sep, "usr", "local", "etc", "bunkerweb", "pro", "plugins")
 
 TMP_PATH = Path(sep, "var", "tmp", "bunkerweb")
 NGINX_TMP_VARIABLES_PATH = TMP_PATH.joinpath("variables.env")
@@ -284,9 +284,15 @@ def handle_reload(signum, frame):
             proc = subprocess_run(
                 [
                     sys_executable,
-                    BUNKERWEB_PATH.joinpath("gen", "save_config.py").as_posix(),
+                    BUNKERWEB_PATH.joinpath("common", "gen", "save_config.py").as_posix(),
                     "--settings",
-                    BUNKERWEB_PATH.joinpath("settings.json").as_posix(),
+                    BUNKERWEB_PATH.joinpath("common", "settings.json").as_posix(),
+                    "--core",
+                    BUNKERWEB_PATH.joinpath("common", "core").as_posix(),
+                    "--plugins",
+                    EXTERNAL_PLUGINS_PATH.as_posix(),
+                    "--pro-plugins",
+                    PRO_PLUGINS_PATH.as_posix(),
                     "--variables",
                     join(sep, "etc", "bunkerweb", "variables.env"),
                 ],
@@ -715,7 +721,7 @@ def get_plugin_validator() -> Configurator:
     global PLUGIN_VALIDATOR
 
     if PLUGIN_VALIDATOR is None:
-        PLUGIN_VALIDATOR = Configurator(BUNKERWEB_PATH / "settings.json", BUNKERWEB_PATH / "core", [], [], {}, LOGGER)
+        PLUGIN_VALIDATOR = Configurator(BUNKERWEB_PATH / "common" / "settings.json", BUNKERWEB_PATH / "common" / "core", [], [], {}, LOGGER)
     return PLUGIN_VALIDATOR
 
 
@@ -891,11 +897,17 @@ def generate_configs(logger: Logger = LOGGER) -> bool:
     proc = subprocess_run(
         [
             sys_executable,
-            BUNKERWEB_PATH.joinpath("gen", "main.py").as_posix(),
+            BUNKERWEB_PATH.joinpath("common", "gen", "main.py").as_posix(),
             "--settings",
-            BUNKERWEB_PATH.joinpath("settings.json").as_posix(),
+            BUNKERWEB_PATH.joinpath("common", "settings.json").as_posix(),
+            "--core",
+            BUNKERWEB_PATH.joinpath("common", "core").as_posix(),
+            "--plugins",
+            EXTERNAL_PLUGINS_PATH.as_posix(),
+            "--pro-plugins",
+            PRO_PLUGINS_PATH.as_posix(),
             "--templates",
-            BUNKERWEB_PATH.joinpath("confs").as_posix(),
+            BUNKERWEB_PATH.joinpath("common", "confs").as_posix(),
             "--output",
             CONFIG_PATH.as_posix(),
         ],
@@ -1632,9 +1644,15 @@ def main() -> None:
             proc = subprocess_run(
                 [
                     sys_executable,
-                    BUNKERWEB_PATH.joinpath("gen", "save_config.py").as_posix(),
+                    BUNKERWEB_PATH.joinpath("common", "gen", "save_config.py").as_posix(),
                     "--settings",
-                    BUNKERWEB_PATH.joinpath("settings.json").as_posix(),
+                    BUNKERWEB_PATH.joinpath("common", "settings.json").as_posix(),
+                    "--core",
+                    BUNKERWEB_PATH.joinpath("common", "core").as_posix(),
+                    "--plugins",
+                    EXTERNAL_PLUGINS_PATH.as_posix(),
+                    "--pro-plugins",
+                    PRO_PLUGINS_PATH.as_posix(),
                     "--first-run",
                     "--variables",
                     env_file_path.as_posix(),
@@ -1695,9 +1713,15 @@ def main() -> None:
             proc = subprocess_run(
                 [
                     sys_executable,
-                    BUNKERWEB_PATH.joinpath("gen", "save_config.py").as_posix(),
+                    BUNKERWEB_PATH.joinpath("common", "gen", "save_config.py").as_posix(),
                     "--settings",
-                    BUNKERWEB_PATH.joinpath("settings.json").as_posix(),
+                    BUNKERWEB_PATH.joinpath("common", "settings.json").as_posix(),
+                    "--core",
+                    BUNKERWEB_PATH.joinpath("common", "core").as_posix(),
+                    "--plugins",
+                    EXTERNAL_PLUGINS_PATH.as_posix(),
+                    "--pro-plugins",
+                    PRO_PLUGINS_PATH.as_posix(),
                     "--variables",
                     env_file_path.as_posix(),
                 ],
