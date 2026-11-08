--- src/scheduler/main.py.orig	2026-10-15 11:22:16 UTC
+++ src/scheduler/main.py
@@ -23,7 +23,7 @@ from typing import Any, Dict, List, Literal, Optional,
 from traceback import format_exc
 from typing import Any, Dict, List, Literal, Optional, Set, Tuple, Union, cast
 
-BUNKERWEB_PATH = Path(sep, "usr", "share", "bunkerweb")
+BUNKERWEB_PATH = Path(sep, "usr", "local", "share", "bunkerweb")
 
 for deps_path in [BUNKERWEB_PATH.joinpath(*paths).as_posix() for paths in (("deps", "python"), ("utils",), ("api",), ("db",), ("gen",))]:
     if deps_path not in sys_path:
@@ -76,7 +76,7 @@ CACHE_PATH.mkdir(parents=True, exist_ok=True)
 CACHE_PATH = Path(sep, "var", "cache", "bunkerweb")
 CACHE_PATH.mkdir(parents=True, exist_ok=True)
 
-CUSTOM_CONFIGS_PATH = Path(sep, "etc", "bunkerweb", "configs")
+CUSTOM_CONFIGS_PATH = Path(sep, "usr", "local", "etc", "bunkerweb", "configs")
 CUSTOM_CONFIGS_PATH.mkdir(parents=True, exist_ok=True)
 CUSTOM_CONFIGS_DIRS = (
     "http",
@@ -93,13 +93,13 @@ for custom_config_dir in CUSTOM_CONFIGS_DIRS:
 for custom_config_dir in CUSTOM_CONFIGS_DIRS:
     CUSTOM_CONFIGS_PATH.joinpath(custom_config_dir).mkdir(parents=True, exist_ok=True)
 
-CONFIG_PATH = Path(sep, "etc", "nginx")
+CONFIG_PATH = Path(sep, "usr", "local", "etc", "nginx")
 NGINX_VARIABLES_PATH = CONFIG_PATH.joinpath("variables.env")
 
-EXTERNAL_PLUGINS_PATH = Path(sep, "etc", "bunkerweb", "plugins")
+EXTERNAL_PLUGINS_PATH = Path(sep, "usr", "local", "etc", "bunkerweb", "plugins")
 EXTERNAL_PLUGINS_PATH.mkdir(parents=True, exist_ok=True)
 
-PRO_PLUGINS_PATH = Path(sep, "etc", "bunkerweb", "pro", "plugins")
+PRO_PLUGINS_PATH = Path(sep, "usr", "local", "etc", "bunkerweb", "pro", "plugins")
 PRO_PLUGINS_PATH.mkdir(parents=True, exist_ok=True)
 
 TMP_PATH = Path(sep, "var", "tmp", "bunkerweb")
@@ -271,9 +271,15 @@ def handle_reload(signum, frame):
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
@@ -560,7 +566,7 @@ def get_plugin_validator() -> Configurator:
     global PLUGIN_VALIDATOR
 
     if PLUGIN_VALIDATOR is None:
-        PLUGIN_VALIDATOR = Configurator(BUNKERWEB_PATH / "settings.json", BUNKERWEB_PATH / "core", [], [], {}, LOGGER)
+        PLUGIN_VALIDATOR = Configurator(BUNKERWEB_PATH / "common" / "settings.json", BUNKERWEB_PATH / "common" / "core", [], [], {}, LOGGER)
     return PLUGIN_VALIDATOR
 
 
@@ -736,11 +742,17 @@ def generate_configs(logger: Logger = LOGGER) -> bool:
     proc = subprocess_run(
         [
             sys_executable,
-            BUNKERWEB_PATH.joinpath("gen", "main.py").as_posix(),
+            BUNKERWEB_PATH.joinpath("common", "gen", "main.py").as_posix(),
             "--settings",
-            BUNKERWEB_PATH.joinpath("settings.json").as_posix(),
+            BUNKERWEB_PATH.joinpath("common", "settings.json").as_posix(),
             "--templates",
-            BUNKERWEB_PATH.joinpath("confs").as_posix(),
+            BUNKERWEB_PATH.joinpath("common", "confs").as_posix(),
+            "--core",
+            BUNKERWEB_PATH.joinpath("common", "core").as_posix(),
+            "--plugins",
+            EXTERNAL_PLUGINS_PATH.as_posix(),
+            "--pro-plugins",
+            PRO_PLUGINS_PATH.as_posix(),
             "--output",
             CONFIG_PATH.as_posix(),
         ],
@@ -1219,9 +1231,15 @@ if __name__ == "__main__":
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
@@ -1284,9 +1302,15 @@ if __name__ == "__main__":
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
