Description: Read the configuration from %%PREFIX%%/etc/napalm/logs.
Issue ID: none
Changeset: https://github.com/napalm-automation/napalm-logs/pull/394 (open,
  not ours)
TODO: FreeBSD-specific path, not for upstream.

--- napalm_logs/config/__init__.py.orig	2026-10-12 14:27:40 UTC
+++ napalm_logs/config/__init__.py
@@ -10,7 +10,8 @@ ROOT_DIR = "/"
 
 # config
 ROOT_DIR = "/"
-CONFIG_FILE = os.path.join(ROOT_DIR, "etc", "napalm", "logs")
+#CONFIG_FILE = os.path.join(ROOT_DIR, "etc", "napalm", "logs")
+CONFIG_FILE = os.path.join("%%PREFIX%%", "etc", "napalm", "logs")
 ADDRESS = "0.0.0.0"
 PORT = 514
 LISTENER = "udp"
