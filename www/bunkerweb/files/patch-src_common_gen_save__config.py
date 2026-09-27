--- src/common/gen/save_config.py.orig	2026-05-28 20:12:40 UTC
+++ src/common/gen/save_config.py
@@ -32,10 +32,10 @@
     try:
         # Parse arguments
         parser = ArgumentParser(description="BunkerWeb config saver")
-        parser.add_argument("--settings", default=join(sep, "usr", "share", "bunkerweb", "settings.json"), type=str, help="file containing the main settings")
-        parser.add_argument("--core", default=join(sep, "usr", "share", "bunkerweb", "core"), type=str, help="directory containing the core plugins")
-        parser.add_argument("--plugins", default=join(sep, "etc", "bunkerweb", "plugins"), type=str, help="directory containing the external plugins")
-        parser.add_argument("--pro-plugins", default=join(sep, "etc", "bunkerweb", "pro", "plugins"), type=str, help="directory containing the pro plugins")
+        parser.add_argument("--settings", default=join(sep, "usr", "local", "share", "bunkerweb", "common", "settings.json"), type=str, help="file containing the main settings")
+        parser.add_argument("--core", default=join(sep, "usr", "local", "share", "bunkerweb", "common", "core"), type=str, help="directory containing the core plugins")
+        parser.add_argument("--plugins", default=join(sep, "usr", "local", "etc", "bunkerweb", "plugins"), type=str, help="directory containing the external plugins")
+        parser.add_argument("--pro-plugins", default=join(sep, "usr", "local", "etc", "bunkerweb", "pro", "plugins"), type=str, help="directory containing the pro plugins")
         parser.add_argument("--variables", type=str, help="path to the file containing environment variables")
         parser.add_argument("--init", action="store_true", help="Only initialize the database")
         parser.add_argument("--method", default="scheduler", type=str, help="The method that is used to save the config")
