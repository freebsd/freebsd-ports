--- src/api/app/config.py.orig	2026-05-10 11:25:04 UTC
+++ src/api/app/config.py
@@ -57,8 +57,8 @@ class ApiConfig(YamlBaseSettings):
     API_RATE_LIMIT_EXEMPT_IPS: Optional[str] = None
 
     model_config = YamlSettingsConfigDict(  # type: ignore
-        yaml_file=getenv("SETTINGS_YAML_FILE", "/etc/bunkerweb/api.yml"),
-        env_file=getenv("SETTINGS_ENV_FILE", "/etc/bunkerweb/api.env"),
+        yaml_file=getenv("SETTINGS_YAML_FILE", "/usr/local/etc/bunkerweb/api.yml"),
+        env_file=getenv("SETTINGS_ENV_FILE", "/usr/local/etc/bunkerweb/api.env"),
         secrets_dir=getenv("SETTINGS_SECRETS_DIR", "/run/secrets"),
         env_file_encoding="utf-8",
         extra="allow",
