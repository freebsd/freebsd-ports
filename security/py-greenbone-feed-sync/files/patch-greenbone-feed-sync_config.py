--- greenbone/feed/sync/config.py	2023-08-31 07:57:04.000000000 -0500
+++ greenbone/feed/sync/config.py	2023-10-20 10:18:44.157521000 -0500
@@ -69,10 +69,10 @@
 DEFAULT_GVMD_LOCK_FILE_PATH = "gvm/feed-update.lock"
 DEFAULT_OPENVAS_LOCK_FILE_PATH = "openvas/feed-update.lock"
 
-DEFAULT_CONFIG_FILE = "/etc/gvm/greenbone-feed-sync.toml"
-DEFAULT_USER_CONFIG_FILE = "~/.config/greenbone-feed-sync.toml"
+DEFAULT_CONFIG_FILE = "%%LOCALBASE%%/etc/gvm/greenbone-feed-sync.toml"
+DEFAULT_USER_CONFIG_FILE = "%%LOCALBASE%%/etc/gvm/greenbone-feed-sync.toml"
 
-DEFAULT_ENTERPRISE_KEY_PATH = "/etc/gvm/greenbone-enterprise-feed-key"
+DEFAULT_ENTERPRISE_KEY_PATH = "%%LOCALBASE%%/etc/gvm/greenbone-enterprise-feed-key"
 
 DEFAULT_GROUP = "gvm"
 DEFAULT_USER = "gvm"
