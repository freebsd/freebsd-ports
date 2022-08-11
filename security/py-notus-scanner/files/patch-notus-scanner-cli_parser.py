--- notus/scanner/cli/parser.py	2022-07-31 23:45:49.051030000 -0500
+++ notus/scanner/cli/parser.py	2022-07-31 23:46:07.662584000 -0500
@@ -29,7 +29,7 @@
 
 logger = logging.getLogger(__name__)
 
-DEFAULT_CONFIG_FILE = "/etc/gvm/notus-scanner.toml"
+DEFAULT_CONFIG_FILE = "%%LOCALBASE%%/etc/gvm/notus-scanner.toml"
 DEFAULT_USER_CONFIG_FILE = "~/.config/notus-scanner.toml"
 
 
