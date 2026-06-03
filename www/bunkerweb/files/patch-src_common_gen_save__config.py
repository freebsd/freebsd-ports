--- src/common/gen/save_config.py.orig	2026-05-28 20:12:40 UTC
+++ src/common/gen/save_config.py
@@ -31,7 +31,7 @@ if __name__ == "__main__":
     try:
         # Parse arguments
         parser = ArgumentParser(description="BunkerWeb config saver")
-        parser.add_argument("--settings", default=join(sep, "usr", "share", "bunkerweb", "settings.json"), type=str, help="file containing the main settings")
+        parser.add_argument("--settings", default=join(sep, "usr", "local", "share", "bunkerweb", "common", "settings.json"), type=str, help="file containing the main settings")
         parser.add_argument("--core", default=join(sep, "usr", "share", "bunkerweb", "core"), type=str, help="directory containing the core plugins")
         parser.add_argument("--plugins", default=join(sep, "etc", "bunkerweb", "plugins"), type=str, help="directory containing the external plugins")
         parser.add_argument("--pro-plugins", default=join(sep, "etc", "bunkerweb", "pro", "plugins"), type=str, help="directory containing the pro plugins")
@@ -177,7 +177,7 @@ if __name__ == "__main__":
                 # Use API builder to compute scheme and port from URL or parts
                 endpoint = API.build_endpoint(
                     bw_instance,
-                    port=settings.get("API_HTTP_PORT"),
+                    port=settings.get("HTTP_PORT", "80"),
                     listen_https=(settings.get("API_LISTEN_HTTPS", "no") or "no").lower() == "yes",
                     https_port=settings.get("API_HTTPS_PORT"),
                 )
