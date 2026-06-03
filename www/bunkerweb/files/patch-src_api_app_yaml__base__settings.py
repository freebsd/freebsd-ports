--- src/api/app/yaml_base_settings.py.orig	2026-05-10 11:25:04 UTC
+++ src/api/app/yaml_base_settings.py
@@ -176,7 +176,7 @@ class YamlBaseSettings(BaseSettings):
     # Baseline defaults; models can override via their own model_config
     model_config = SettingsConfigDict(
         secrets_dir=getenv("SETTINGS_SECRETS_DIR", "/etc/secrets"),
-        yaml_file=getenv("SETTINGS_YAML_FILE", "/etc/bunkerweb/config.yml"),
+        yaml_file=getenv("SETTINGS_YAML_FILE", "/usr/local/etc/bunkerweb/config.yml"),
     )  # type: ignore
 
 
