--- src/onedrivegui/global_config.py.orig	2026-10-25 06:06:24 UTC
+++ src/onedrivegui/global_config.py
@@ -7,8 +7,7 @@ from configparser import ConfigParser
 # from logger import logger
 from configparser import ConfigParser
 
-
-DIR_PATH = os.path.dirname(os.path.realpath(__file__))
+DIR_PATH = "%%DATADIR%%"
 PROFILES_FILE = os.path.expanduser("~/.config/onedrive-gui/profiles")
 
 # Options removed from the OneDrive client. 'min_notify_changes' and 'force_http_2'
