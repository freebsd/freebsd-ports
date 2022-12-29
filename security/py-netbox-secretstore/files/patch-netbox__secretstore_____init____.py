Adjust version check to allow NetBox 3.3.10

https://github.com/DanSheps/netbox-secretstore/pull/106

--- netbox_secretstore/__init__.py.orig	2022-12-14 09:03:13 UTC
+++ netbox_secretstore/__init__.py
@@ -18,7 +18,7 @@ class NetBoxSecretStore(PluginConfig):
     author_email = metadata.get('Author-email')
     base_url = 'netbox_secretstore'
     min_version = '3.3.0beta1'
-    max_version = '3.3.9'
+    max_version = '3.3.10'
     required_settings = []
     default_settings = {
         'public_key_size': 2048
