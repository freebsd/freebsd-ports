--- notus/scanner/cli/parser.py	2023-08-30 03:14:56.000000000 -0500
+++ notus/scanner/cli/parser.py	2023-10-20 18:26:27.530523000 -0500
@@ -16,9 +16,8 @@
 
 logger = logging.getLogger(__name__)
 
-DEFAULT_CONFIG_FILE = "/etc/gvm/notus-scanner.toml"
-DEFAULT_USER_CONFIG_FILE = "~/.config/notus-scanner.toml"
-
+DEFAULT_CONFIG_FILE = "%%LOCALBASE%%/etc/gvm/notus-scanner.toml"
+DEFAULT_USER_CONFIG_FILE = "%%LOCALBASE%%/etc/gvm/notus-scanner.toml"
 
 def log_level(string: str) -> str:
     """Check if provided string is a valid log level."""
